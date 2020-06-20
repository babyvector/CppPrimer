/*
    14.51Q：在调用calc的过程中，可能用到哪些类型转换序列呢？说明最佳可行函数是如何被选出来的。
    A:自己经过实现得到的产生的调用是：calc(int)这个函数；可能原因是更加优先的选择系统内置的运算符转换。
    web-A:最佳匹配的函数是：void calc(int).因为类类型的转换选择的优先级是排在最低的。
           重新看一下匹配的顺序：
           1.exact match                        //最佳匹配
           2.const conversion                   //const 转换
           3.promotion                          //提升
           4.arithmetic or pointer conversion   //算术或指针转换
           5.class-type conversion              //类类型的转换
*/

#include <iostream>

using namespace std;

struct LongDouble{
    LongDouble(double = 0.0){};
    operator double(){return 0.0;};
    operator float(){return 0.0;};
};

void calc(int){cout<<"invoking calc(int);"<<endl;};
void calc(LongDouble){cout<<"invoking calc(LongDouble);"<<endl;};

int main(){

    double dval;
    calc(dval);

    return 0;
}