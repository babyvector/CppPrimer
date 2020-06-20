#ifndef _15_35_NEWQUERY_HPP_
#define _15_35_NEWQUERY_HPP_


#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <memory>
#include "12_32_constStrBlobPtr.hpp"

using namespace std;

class QueryResult{
    friend std::ostream& print(std::ostream&, const QueryResult&);
    public:
        using line_no = std::vector<std::string>::size_type;
        QueryResult(std::string s,
                    std::shared_ptr<std::set<line_no>>p,
                    std::shared_ptr< vector<string>>f):
            sought(s),lines(p),file(f){};
        set<line_no>::iterator begin(){return lines->begin();}
        set<line_no>::iterator end(){return lines->end();}
        auto& get_file(){return file;}
    private:
        std::string sought;             //查询单词
        std::shared_ptr<set<line_no>>lines;    //出现的行号
        std::shared_ptr<vector<string>>file;    //输入文件
};
class TextQuery{
    public:
        using line_no = std::vector<std::string>::size_type;
        TextQuery(std::ifstream&);
        QueryResult query(const std::string&) const;
    private:
        std::shared_ptr<std::vector<std::string>>file;//输入文件
        //每个单词到它所在的行号的集合的映射
        map<string, shared_ptr<set<line_no>>>wm;
};

void runQueries(ifstream &infile);

class Query_base
{
        friend class Query;
    protected:
        using line_no = TextQuery::line_no;
        virtual ~Query_base() = default;
    private:
        virtual QueryResult eval(const TextQuery&) const = 0;
        virtual string rep() const = 0;
};

class WordQuery;
class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query& , const Query&);
    friend Query operator&(const Query&, const Query&);
    friend ostream& operator<<(ostream&os, const Query& query);
    public:
        Query(const string& s);
        QueryResult eval(const TextQuery& t) const
            {return q->eval(t);}
        string rep() const
            {
                cout<<"Query::rep()"<<endl;
                return q->rep();
            }
    protected:
    private:
        Query(shared_ptr<Query_base>query):q(query){};
        shared_ptr<Query_base>q;
};

class WordQuery: public Query_base
{
    friend class Query;
    WordQuery(const string&s):query_word(s){cout<<"invoking WordQuery constructor."<<endl;}
    QueryResult eval(const TextQuery& t) const
        {return t.query(query_word);}
    string rep() const
        {
            cout<<"invoking WordQuery rep."<<endl;
            return query_word;
        }

    string query_word;      //要查找的单词
};

class NotQuery:public Query_base
{
        friend Query operator~(const Query&not_query);
    protected:
        NotQuery(const Query& query, const string& opSym):q(query),sym(opSym){
            cout<<"invoking NotQuery constructor."<<endl;
        }
        QueryResult eval(const TextQuery& t) const;
        string rep()const {
            cout<<"invoking NotQuery rep."<<endl;
            return "~" + q.rep();}
        Query q;
        string sym;
};

/*
QueryResult NotQuery::eval(const TextQuery& t) const
{
    
}
*/
class BinaryQuery:public Query_base
{
    //自己的eval和rep函数仍然是虚函数，但是应不应该继续写出来... const = 0
    protected:
    BinaryQuery(const Query&lquery, const Query&rquery, const string& opSym):
        ql(lquery), qr(rquery),sym(opSym){
            cout<<"invoking BinaryQuery constructor."<<endl;
        };
    string rep()const{
        cout<<"invoking BinaryQuery rep."<<endl;
        return "("+ql.rep()+" "+sym+" "+qr.rep()+")";
        }
    Query ql, qr;
    string sym;

};

class AndQuery:public BinaryQuery
{
    friend class Query;
    friend Query operator&(const Query&lquery, const Query&rquery);
    AndQuery(const Query& lquery, const Query& rquery, const string& opSym):
        BinaryQuery(lquery, rquery, opSym){
            cout<<"invoking AndQuery constructor."<<endl;
        }
    QueryResult eval(const TextQuery& t) const;
};

/*
QueryResult AndQuery::eval(const TextQuery& t) const
{
    
}
*/

class OrQuery:public BinaryQuery
{
    friend Query operator|(const Query&lquery , const Query&rquery);
    OrQuery(const Query& lquery, const Query& rquery, const string& opSym):
        BinaryQuery(lquery, rquery, opSym){
            cout<<"invoking OrQuery constructor."<<endl;
        }
    QueryResult eval(const TextQuery& t) const;
};

/*
QueryResult OrQuery::eval(const TextQuery& t) const
{
    
}
*/


#endif

