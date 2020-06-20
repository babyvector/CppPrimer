#include <iostream>
#include <fstream>
#include "12_27_28_29_TextQuery.hpp"
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
/*
class func_class{
    public:
        func_class();
        func_class(func_class &obj);
        func_class(top_func_class & obj);
        func_class(bottom_func_class & obj);
        virtual void read(int a);
        void write(){
            cout<<"in func_class we write."<<endl;
        }
    private:
        int a;
};
class top_func_class : func_class{
    public:
        void read(int a){
            cout<<"top_func_class"<<endl;
        }
};
class bottom_func_class :public func_class{
    public:
        void read(int a){
            cout<<"bottom_func_class"<<endl;
        }
} ;
*/
int main(){
    /*
        1. 注意auto &lines用法44行，注意拓展。
        2. 注意整个打印的过程，函数的使用
        3. 注意文件的快速使用
        4. 注意行中字符的分解
        5. 注意实验虚函数，和重写函数的相关内容
        6. 多线程问题，线程同步问题
    */
    /*
    int a = 10;
    int &b = a;
    cout<<"a is:"<<a<<endl;
    cout<<"b is:"<<b<<endl;
    b = 20;
    cout<<"we fix the b value."<<endl;
    cout<<"a is:"<<a<<endl;
    cout<<"b is:"<<b<<endl;
    //virtual function test
    bottom_func_class test;
    test.read(10);
    test.write();
    vector<func_class>all_thing_cont;
    all_thing_cont.push_back(test);
    */
    ifstream infile("english_articles.txt");
    runQueries(infile);
    return 0;
}