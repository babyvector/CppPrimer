#include "14_21_Sales_data.hpp"


int main(){

     Sales_data a("史海沉浮", 20, 29.9);
     Sales_data b("史海沉浮", 30, 29.9);
     cout<<a<<endl;
     cout<<(a+b)<<endl;

     return 0;
 }

 /*
    优缺点讨论：
    +=号执行起来更有效率，因为调用+号的时候会生成一个新的对象，而且生成对象之后还要进行拷贝。
    浪费了时间和空间。
 */