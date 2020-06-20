#include "14_18_StrVec.hpp"

using namespace std;

int main(){

    StrVec a, b;
    a.push_back("xiaoming");//only push_back(const string&) can push back lvalue string;
    b.push_back("xiaohua");
    b.push_back("xiaohui");

    cout<<"StrVec test < :"<<(a < b)<<endl;
    cout<<"StrVec test < :"<<(b < a)<<endl;

    return 0;
}