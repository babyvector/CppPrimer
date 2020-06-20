#include "14_16_String.hpp"

using namespace std;

int main(){

    String a("xiaoming");
    String b(move(a));
    cout<<"String a is:"<<a<<endl;
    cout<<"String b is:"<<b<<endl;
    cout<<"String a.element:"<<a.begin()<<endl;//broke here!
    cout<<"String b.element:"<<b.begin()<<endl;
    cout<<"test String == :"<<(a == b)<<endl;
    
    return 0;
}