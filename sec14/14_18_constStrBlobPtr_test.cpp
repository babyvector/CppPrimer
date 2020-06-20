#include "14_18_constStrBlobPtr.hpp"

using namespace std;

 int main(){

     StrBlob a, b;
     a.push_back("xiaoming");
     b.push_back("xiaohua");
     b.push_back("xiaoping");

     cout<<"test < :"<<(a < b)<<endl;

     return 0;
 }