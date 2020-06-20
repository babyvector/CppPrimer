/*
    14.50Q:在初始化ex1和ex2的过程中，可能用到哪些类类型的转换序列呢？说明初始化是否正确并解释原因。
    A:int ex1 = ldobj;是不正确的；因为在这个过程中ldobj要先转为double 或者 float类型的（在转换的过程中有歧义）然后经过内置的转换再转换成int类型的；
*/
#include <iostream>

using namespace std;

struct LongDouble{
    LongDouble(double = 0.0){};
    operator double(){return 0.0;};
    operator float(){return 0.0;};
};

int main(){
    LongDouble ldobj;
    int ex1 = ldobj;
    float ex2 = ldobj;
    return 0;
}