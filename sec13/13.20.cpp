/*
    解释当我们拷贝、赋值或销毁TextQuery和QueryResult类
    对象时会发生什么？
*/

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
        QueryResult(QueryResult&) = delete;
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

int main(){
    /*
        1. 注意auto &lines用法44行，注意拓展。
        2. 注意整个打印的过程，函数的使用
        3. 注意文件的快速使用
        4. 注意行中字符的分解
        5. 注意实验虚函数，和重写函数的相关内容
        6. 多线程问题，线程同步问题
    */

    ifstream infile("english_articles.txt");
    runQueries(infile);

    /*
        13.20
        对于QueryResult和TextQuery拷贝函数是默认的拷贝函数
        赋值函数也是默认的赋值的函数，当调用这两个函数的时候
        都会发生，申请的指针的复制，指向同一个对象；当销毁的
        时候会发生如果是shared_ptr则会递减引用，如果不是就
        释放这个指针指向的对象，并默认的析构函数会调用指针
        指向的对象的析构函数来释放对象。


        13.21
        我认为不需要，因为编译器给我们合成的拷贝操作已经够用
        
        
    */
    return 0;
}