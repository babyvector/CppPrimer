#ifndef _12_32_TEXTQUERY_HPP_
#define _12_32_TEXTQUERY_HPP_


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
class TextQuery;
class QueryResult{
    friend class StrBlob;
    friend std::ostream& print(std::ostream&, const QueryResult&);
    public:
        using line_no = std::vector<std::string>::size_type;
        QueryResult(std::string s,
                    std::shared_ptr<std::set<line_no>>p,
                    StrBlob f):
            sought(s),lines(p),file(f){};
    private:
        std::string sought;             //查询单词
        std::shared_ptr<set<line_no>>lines;    //出现的行号
        StrBlob file;    //输入文件
};
class TextQuery{
    friend class StrBlob;
    public:
        using line_no = std::vector<std::string>::size_type;
        TextQuery(std::ifstream&);
        QueryResult query(const std::string&) const;
    private:
        StrBlob file;//输入文件
        //每个单词到它所在的行号的集合的映射
        map<string, shared_ptr<set<line_no>>>wm;
};
void runQueries(ifstream &infile);
#endif

