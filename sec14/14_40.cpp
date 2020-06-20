#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LenCompare
{
public:
    int operator()(const string& lhs)
    {
        return lhs.length();
    }
};

void elimDups(vector<string> &words)
{
    //按字典序排序words，以便查找重复单词
    sort( words.begin(), words.end() );
    //unique重排输入范围，使得每个单词只出现一次
    //排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
    auto end_unique = unique(words.begin(), words.end());
    //使用向量操作erase删除重复单词
    words.erase(end_unique, words.end());
}

class Fun1ClassForBigger
{
public:
    bool operator()(const string& a, const string& b)
    {
        return a.size() < b.size();
    }
};

class Fun2ClassForBigger
{
public:
    Fun2ClassForBigger(size_t input):sz(input){};
    bool operator()(const string& a)
    {
        return a.size() >= sz;
    }
private:
    vector<string>::size_type sz;
};

class Fun3ClassForBigger
{
public:

    Fun3ClassForBigger(ostream& os_cout, const string& input_string):os(os_cout), mm(input_string){};
    
    void operator()(const string& to_print)
    {
        os<<to_print<<mm;
    }
private:
    ostream& os;
    const string& mm;
};

void biggiers(vector<string> &words, vector<string>::size_type sz)
{
    
    elimDups(words);//将words按字典序排序，删除重复单词
    //按长度排序，长度相同的单词维持字典序

    stable_sort(words.begin(), words.end(), Fun1ClassForBigger());
    //获取一个迭代器，指向第一个满足size()>=sz的元素
    auto first_elem = find_if(words.begin(),words.end(), Fun2ClassForBigger(sz));
    //计算满足size >= sz的元素的数目
    int num = 0;
    num = words.end() - first_elem;
    //打印长度大于等于给定值的单词，每个单词后面接一个空格
    for_each(first_elem, words.end(), Fun3ClassForBigger(cout, " "));
    cout<<endl;
    
}

int main(){

    fstream infile("english_articles.txt");
    string line_string;
    
    vector<string> words;

    while(getline(infile, line_string))
    {
        stringstream sstring(line_string);
        string tmp;
        while(sstring >> tmp){
            words.push_back(tmp);          
        }
    }

    biggiers(words, 9);

    return 0;
}