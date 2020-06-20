/*
    14.52Q：假定我们已经定义了如第522页所示的SmallInt,判断下面的加法表达式是否合法。
            如果合法使用了哪个加法运算符？如果不合法，应该怎样修改代码才能使其合法？
    A:      不合法，因为在调用+号的时候会产生重载；'operator+(int, double)' <built-in>和'SmallInt operator+(const SmallInt&, const SmallInt&)'
    web-A:  double d = s1 + SmallInt(3.14);

*/

#include <iostream>

using namespace std;

class SmallInt{

friend
    SmallInt operator+(const SmallInt&, const SmallInt&){cout<<"invoking the operator+();"<<endl;};
public:
    SmallInt(int = 0){cout<<"invoking the SmallInt(int)"<<endl;};                          //转换源为int的类型转换
    operator int() const{return val;}           //转换目标为int的类型转换
private:
    std::size_t val;    

};

int main(){
    
    SmallInt s1;
    double d = s1 + SmallInt(3.14);

    return 0;
}