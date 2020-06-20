#include <iostream>
#include <algorithm>
#include <string>
#include "13_39_StrVec.hpp"
using namespace std;

int main(){
    
    StrVec sv;
    string s1 = "xyk";
    int i = 0;
    while(i++<10){
        s1 += "xyk";
        sv.push_back(s1);
    }

    cout<<"we are going to print."<<endl;
    for_each(sv.begin(), sv.end(), [](auto s){cout<<s<<endl;});
    return 0;
}

/*
 * 用for_each()算法配合lambda表达式使代码更加简洁，但是要引入一个新的头文件具体
 * 从代码简洁性上更加值得提倡。我更加倾向于使用lamda表达式来实现。
 */