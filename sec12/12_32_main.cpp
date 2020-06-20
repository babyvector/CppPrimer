#include <iostream>
#include <fstream>
#include "12_32_TextQuery.hpp"

using namespace std;

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