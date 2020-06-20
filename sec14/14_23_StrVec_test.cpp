#include "14_23_StrVec.hpp"
#include <algorithm>

using namespace std;

int main(){

    StrVec a, b;
    a.push_back("xiaoming");//only push_back(const string&) can push back lvalue string;
    b.push_back("xiaohua");
    b.push_back("xiaohui");

    cout<<"StrVec test < :"<<(a < b)<<endl;
    cout<<"StrVec test < :"<<(b < a)<<endl;

    StrVec c = {"what ", "is ", "your ", "name?"};
    for_each(c.begin(),c.end(), [](const string& item){cout<<item;});

    return 0;
}