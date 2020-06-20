#include "15_35_NewQuery.hpp"
#include <iostream>
#include <fstream>

TextQuery::TextQuery(ifstream &is):file(new vector<string>()){
    string text;
    while(getline(is, text)){           //对文本中的每一行
        file->push_back(text);          //保存此行文本
        int n = file->size() - 1;       //当前行号
        istringstream line(text);       //将行文本分解为单词
        string word;
        while(line>>word){              //对行中每个单词
            //如果单词不再wm中，以之为下标在wm中添加一项
            auto &lines = wm[word];     //lines是一个shared_ptr
            if(!lines)                  //在我们第一次遇到这个单词时，此指针为空
                lines.reset(new set<line_no>);  //分配一个新的set
            lines->insert(n);           //将此行号插入set中
        }
    }
}

QueryResult
TextQuery::query(const string &sought) const
{
    //如果未找到sought，我们将返回一个指向此set的指针
    static shared_ptr<set<line_no>>nodata(new set<line_no>);
    //使用find而不是下标运算符来查找单词，避免将单词添加到wm中！
    auto loc = wm.find(sought);
    if(loc == wm.end())
        return QueryResult(sought, nodata, file);//未找到
    else
        return QueryResult(sought, loc->second, file);
}

string make_plural(size_t ctr, const string &word, const string &ending){
    return (ctr == 1)?word:word+ending;
}

ostream &print(ostream &os, const QueryResult &qr){
    //如果找到了单词，打印出现次数和所有出现的位置
    os<<qr.sought<<" occurs "<<qr.lines->size()<<" "
      <<make_plural(qr.lines->size(), "time", "s")<<endl;
      //打印单词出现的每一行
      for(auto num : *qr.lines)         //对set中每个单词
        //避免行号从0开始给用户带来困惑
        os<<"\t(line"<<num + 1 <<")"
          <<*(qr.file->begin() + num) <<endl;

       return os;
}

void runQueries(ifstream &infile){
    //infile是一个ifstream，指向我们要处理的文件
    TextQuery tq(infile);//保存文件并建立查询map
    //与用户交互：提示用户输入要查询的单词，完成查询并打印结果
    while(true){
        cout<<"enter word to look for, or q to quit:";
        string s;
        //若遇到文件尾或用户输入q时循环终止
        if(!(cin>>s) || s == "q")break;
        //指向查询并打印结果
        print(cout, tq.query(s))<<endl;
    }
}


QueryResult NotQuery::eval(const TextQuery& t) const{
    cout<<"NotQuery::eval();"<<endl;
    //QueryResult result = t.query();
    //首先确定好不是非的时候的result，然后再在文件中将结果删除
    QueryResult YesResult = q.eval(t);

    auto& file_vec = YesResult.get_file();
    set<line_no>* result_set = new set<line_no>();
    for(int i = 0; i<file_vec->size(); i++)
        result_set->insert(i+1);
    
    //cout<<"q.eval(t) size is: "<<YesResult.end() - YesResult.begin()<<endl;
    for(auto set_iter_start = YesResult.begin(); set_iter_start != YesResult.end(); set_iter_start++){
        result_set->erase(*set_iter_start);
    }
    
    return QueryResult("( "+sym+q.rep()+" )", shared_ptr<set<line_no>>(result_set), file_vec);
}

QueryResult OrQuery::eval(const TextQuery& t) const{
    cout<<"OrQuery::eval();"<<endl;
    //将最终的查询结果合并到一个set中，最后组装成一个QueryResult输出
    QueryResult YesResult_ql = ql.eval(t);
    QueryResult YesResult_qr = qr.eval(t);

    auto& file_vec = YesResult_ql.get_file();
    set<line_no>* result_set = new set<line_no>();

    result_set->insert(YesResult_ql.begin(), YesResult_ql.end());
    result_set->insert(YesResult_qr.begin(), YesResult_qr.end());
    return QueryResult("( "+ql.rep()+sym+qr.rep()+" )", shared_ptr<set<line_no>>(result_set), file_vec);
}

QueryResult AndQuery::eval(const TextQuery& t) const{
    cout<<"AndQuery::eval();"<<endl;

    QueryResult YesResult_ql = ql.eval(t);
    QueryResult YesResult_qr = qr.eval(t);

    auto& file_vec = YesResult_ql.get_file();
    set<line_no>* result_set = new set<line_no>();
    set<line_no>* tmp_set = new set<line_no>();
    tmp_set->insert(YesResult_qr.begin(), YesResult_qr.end());
    for(auto set_iter_start = YesResult_ql.begin(); set_iter_start != YesResult_ql.end(); set_iter_start++)
    {
        if( tmp_set->count(*set_iter_start) > 0){
            result_set->insert(*set_iter_start);
            cout<<"tmp_set get."<<endl;
        }
    }
    
    return QueryResult("( "+ql.rep()+sym+qr.rep()+" )", shared_ptr<set<line_no>>(result_set), file_vec);
}

/*
Query::Query(const string&s):q(new WordQuery(s))
{
    //在这里面运行Query()不能为自身构造;只有上面的形式才能为自己进行构造
    //Query( shared_ptr<Query_base>(new WordQuery(s)) );
}
*/
//一下是进行委托构造
Query::Query(const string&s):Query(shared_ptr<Query_base>(new WordQuery(s))){
    cout<<"invoking Query constructor."<<endl;
}

Query operator~(const Query&not_query)
{
    return Query(shared_ptr<Query_base>(new NotQuery(not_query, "~")));
}

Query operator|(const Query&lquery , const Query&rquery)
{
    //return Query(new AndQuery(lquery, rquery, "|"));    
    return Query(shared_ptr<Query_base>(new OrQuery(lquery, rquery, "|")));
    //return shared_ptr<Query_base>(new AndQuery(lquery, rquery, "|"));
    //二者有何不同
}

Query operator&(const Query&lquery, const Query&rquery)
{
    return Query(shared_ptr<Query_base>(new AndQuery(lquery, rquery, "&")));
}

ostream& operator<<(ostream&os, const Query& query)
{
    os<<query.rep();
    return os;
}