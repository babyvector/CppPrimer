#include "14_16_StrVec.hpp"

using namespace std;

int main(){

    StrVec a, b;
    a.push_back("xiaoming");//only push_back(const string&) can push back lvalue string;
    b.push_back("xiaohua");

    cout<<"StrVec test == :"<<(a == b)<<endl;
    cout<<"StrVec test != :"<<(a != b)<<endl;

    return 0;
}