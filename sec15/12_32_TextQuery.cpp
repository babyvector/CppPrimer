#include <iostream>
#include <fstream>
#include "15_35_NewQuery.hpp"

TextQuery::TextQuery(ifstream &is):file(new StrBlob()){
    //file = new StrBlob();
    string text;
    while(getline(is, text)){           //对文本中的每一行
        file.push_back(text);          //保存此行文本
        int n = file.size() - 1;       //当前行号
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
          <<*(qr.file.begin() + num) <<endl;

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