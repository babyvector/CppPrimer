/*
    15.12:有必要将一个成员函数同时声明为override和final吗？为什么？
    A:如果一个函数已经被声明为override不能起到final的效果，所以如果不想往下派生还要加上final
      但是如果一个成员函数已经声明了final就不用再使用override修饰了，因为已经不能再重载了
*/

//15.13:给定下面的类，解释每个print函数的机理
#include <iostream>
#include <string>


using namespace std;

class base{
public:
    string name(){return basename;}//(1)
    virtual void print(ostream &os){os<<basename;}//(2)
private:
    string basename = "base";
};

class derived:public base{
public:
    void print(ostream &os){base::print(os); os<<" "<<i;}//(3)
private:
    int i;
};

int main(){
    base item;
    derived derived_item;
    item.print(cout);
    derived_item.print(cout);

    return 0;
}
/*
    上面的item直接调用的base中的定义的虚函数去打印string；derived_item调用自己重载的print函数；将cout绑定到自己重载的函数参数上；
    在函数体中调用基类中的print函数，并将os绑定到基类的print函数的形参os上。如果不加上域作用符则程序一直递归的调用自己。

*/

//15.14给定上一题中的类以及下面这些对象，说明在运行时调用哪个函数：
base bobj;      base *bp1 = &bobj;      base &br1 = bobj;
derived dobj;   base *bp2 = &dobj;      base &br2 = dobj;
(a)bobj.print() ->(2)
(b)dobj.print() ->(3)
(c)bp1->name()  ->(1)
(d)bp2->name()  ->(1)
(e)br1.print()  ->(1)
(f)br2.print()  ->(2)
