/*
    14.52Q：在下面的加法表达式中分别选用了哪个operator+?列出候选函数、可行函数及为每个可行函数的实参执行的类型转换：
    A:对于ld = si + ld这一行是调用到了两个系统内置重载:operator+(int, float)与operator+(int, double)这两个重载产生ambiguous overload；对于
      ld = ld + si;产生的情况我不知道原因
    web-A:ld = si+ld 是模棱两可的。ld = ld + si可以同时使用(1)和（2）但是明显应该选择（1）因为（1）更加复合形式

*/

#include <iostream>

using namespace std;

class SmallInt{
friend
    SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int = 0);                          //转换源为int的类型转换
    operator int() const{return val;}           //转换目标为int的类型转换
private:
    std::size_t val;    
};

struct LongDouble{

    LongDouble(double = 0.0){};

    //用于演示的成员operator+;在通常情况下+是个非成员
    LongDouble operator+(const SmallInt&);//（1）
    
    operator double(){return 0.0;};
    operator float(){return 0.0;};
};


int main(){
    //（2）
    LongDouble operator+(LongDouble& a, double b);//注意：如果把这一行放到main的上面就会产生error: expected initializer before 'operator'的错误。
    SmallInt si;
    LongDouble ld;
    //ld = si + ld;
    ld = ld + si;

    return 0;
}