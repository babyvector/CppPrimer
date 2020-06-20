#ifndef _12_27_28_29_TEXTQUERY_HPP_
#define _12_27_28_29_TEXTQUERY_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <memory>

using namespace std;

class QueryResult{
    friend std::ostream& print(std::ostream&, const QueryResult&);
    public:
        using line_no = std::vector<std::string>::size_type;
        QueryResult(std::string s,
                    std::shared_ptr<std::set<line_no>>p,
                    std::shared_ptr< vector<string>>f):
            sought(s),lines(p),file(f){};
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

#endif