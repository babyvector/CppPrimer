/*
    12.16
    如果你试图拷贝或赋值unique_ptr，编译器并不总是能给出易于理解的错误信息。编写包含这种
    错误的程序，观察编译器如何诊断这种错误。

    12.17
    下面的unique_ptr声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪里？
    int ix = 1024, *pi = &ix,*pi2 = new int(2048);
    typedef unique_ptr<int> IntP;
    IntP p0(ix);
    IntP p1(pi);
    IntP p2(pi2);
    IntP p3(&ix);
    IntP p4(new int(2048));
    IntP p5(p2.get());
    答：除了第一个类型使用错误之外其余的全部使用恰当。
    12.18
    为什么shared_ptr中没有release成员？
    答：因为因为shared_ptr指向的内容是shared的如果但方面的release掉，其他指向这块内存的会出错。

    
*/

#include<iostream>
#include<memory>

using namespace std;

int main(){

    int ix = 1024, *pi = &ix,*pi2 = new int(2048);
    typedef unique_ptr<int> IntP;
    //IntP p0(ix);
    IntP p1(pi);
    IntP p2(pi2);
    IntP p3(&ix);
    IntP p4(new int(2048));
    IntP p5(p2.get());
    cout<<"the p5:";
    cout<<*p5<<endl;
    return 0;
}