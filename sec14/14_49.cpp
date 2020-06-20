/*
#include "14_49_Employee.hpp"

int main(){

    Employee ployee_a("", "", 1);
    //进行了对象的部分初始化，这样的做法应该被阻止
    cout<<bool(ployee_a)<<endl;

    return 0;
}
*/

#include <iostream>

using namespace std;

struct B;
struct A{
    A() = default;
    A(const B&);    //把一个B转换成A
    //其他数据成员
};

struct B{
    operator A() const; //也是把一个B转换成A
    //其他数据成员
};


int main(){
    
    A f(const A&);
    B b;
    A a = f(b);

    //B b都是要转换为类型A
    //但是是用  A的构造函数，还是用B的类型转换符？
    //由此产生了二义性


    return 0;

}