/*
    14.33 一个重载的函数调用运算符应该接受几个

    A：接受的运算对象的个数可以根据重载时在函数中定义了几个函数
    web-A:重载的运算符具有与运算符操作数相同数量的参数。因此最大值是256
 */

#include <iostream>

using namespace std;


class IfThenElse{

public:
    int operator()(int item_a, int item_b, int item_c)
    {   
        if(item_a)
            return item_b;
        else
        {
            return item_c;
        }
    } 
private:


};

int main(){

    IfThenElse if_then_else;
    cout<<"test the if-then-else:"<<if_then_else(1, 2, 3)<<endl;

    return 0;
}



