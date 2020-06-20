#include "14_45_Sales_data.hpp"

int main(){
    Sales_data item("xiaowangzi", 10, 29.9);
    cout<<"change type to string: "<<string(item)<<endl;
    cout<<"change type to double: "<<double(item)<<endl;
    return 0;
}

/*
    Q:你认为应该为Sales_data类定义上面两种类型转换运算符吗？应该把他们声明成explicit的吗？为什么？
    A：自己认为应该声明为explicit，因为我们应该显式的告诉读者已经进行了类型转换。
    web-A:因为这些转换会产生误导。explicit应该添加以防隐式转换

*/