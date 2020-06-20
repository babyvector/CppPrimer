#include <iostream>
#include <string>
#include <vector>

using namespace std;

class numbered{
    public:
        numbered():mysn(start_id){
            cout<<"we invoke the construct function."<<endl;
            start_id++;
        }
        int mysn;
        static int start_id;
};
int numbered::start_id = 0;
void f(numbered s){cout<<s.mysn<<endl;}

class numbered1{
    public:
        numbered1():mysn(start_id){
            cout<<"we invoke the construct function."<<endl;
            start_id++;
        }
        numbered1(const numbered1 & obj){
            cout<<"we invoke the copy construct function."<<endl;
            this->mysn = start_id++;
        }
        int mysn;
        static int start_id;
};
int numbered1::start_id = 0;
void f(numbered1 s){cout<<s.mysn<<endl;}
void f1(numbered1& s){cout<<s.mysn<<endl;}

int main(){

/*
    numbered a,b,c,d;
    cout<<a.mysn<<" "<<a.start_id<<endl;
    cout<<b.mysn<<" "<<b.start_id<<endl;
    cout<<c.mysn<<" "<<c.start_id<<endl;
    cout<<d.mysn<<" "<<d.start_id<<endl;
    numbered e;
    cout<<e.mysn<<" "<<e.start_id<<endl;
    cout<<d.mysn<<" "<<d.start_id<<endl;
*/
/*  13.15
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    cout<<a.mysn<<endl;
    cout<<b.mysn<<endl;
    cout<<c.mysn<<endl;
    //输出的结果都是给变量a赋予的唯一一个编号
*/
/*
    numbered1 a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    cout<<a.mysn<<endl;
    cout<<b.mysn<<endl;
    cout<<c.mysn<<endl;

    运行之后的输出结果是：
    we invoke the construct function.
    we invoke the copy construct function.
    we invoke the copy construct function.
    we invoke the copy construct function.
    3
    we invoke the copy construct function.
    4
    we invoke the copy construct function.
    5
    0
    1
    2
    出现这种情况的原因：
        当使用=进行初始化的时候，不再调用构造函数来构造
        变量而是使用拷贝构造函数来直接构造变量所以出现了
        0，1，2这三个对三个变量的初始编号；而当调用函数
        的时候，由于函数的输入参数并不是引用型变量，所以
        会发生变量的拷贝，进而生成三个新的变量，从而这
        三个变量又被赋予了特定的序号。3，4，5
    
*/    
/*  13.16
    numbered1 a, b = a, c = b;
    f1(a);
    f1(b);
    f1(c);
    cout<<a.mysn<<endl;
    cout<<b.mysn<<endl;
    cout<<c.mysn<<endl;
    会出现不同的结果，因为f1函数的形参是引用类型的，所以
    在调用的时候不会再进行变量的拷贝赋值，也就不会有新的
    变量生成，也就不会有新的序号产生。
    13.17
    已经编写了，但是并没有全部预测出来。
*/

    return 0;
}