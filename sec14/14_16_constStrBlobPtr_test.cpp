#include "14_16_constStrBlobPtr.hpp"

using namespace std;

 int main(){

     StrBlob a, b;
     a.push_back("xiaoming");
     b.push_back("xiaohua");

     cout<<"test == :"<<(a == b)<<endl;

     return 0;
 }