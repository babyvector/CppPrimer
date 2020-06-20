#include <iostream>

using namespace std;

class Base{
public:
    void pub_mem();         //public成员
protected:
    int prot_mem;           //protected成员
private:
    char priv_mem;          //private成员
};

struct Pub_Derv:public Base{
    //正确：派生类能访问protected成员
    int f(){return prot_mem;}
    //错误：private成员对于派生类来说是不可访问的
    //char g(){return priv_mem;}

    void memfcn(Base &b){b = *this;}
};

struct Prot_Derv:protected Base{
    //protected也不会影响派生类的访问权限
    int fp() const {return prot_mem;}

    void memfcn(Base &b){b = *this;}
};

struct Priv_Derv:private Base{
    //private不影响派生类的访问权限
    int f1() const{return prot_mem;}

    void memfcn(Base &b){b = *this;}
};

struct Derived_from_Public:public Pub_Derv{
    //正确：Base::prot_mem在Pub_Derv中仍然是protected的
    int use_base(){return prot_mem;}

    void memfcn(Base &b){b = *this;}
};

struct Derived_from_Private:public Priv_Derv{
    //错误:Base::prot_mem在Priv_Derv中是private的
    //int use_base(){return prot_mem;};

    void memfcn(Base &b){b = *this;}
    //这一行出错的原因：priv_Derv是私有继承的，所以Base以后就是他的私有对象了
};

struct Derived_from_Protected:public Prot_Derv{
    int use_base(){return prot_mem;}

    void memfcn(Base &b){b = *this;}
};

/*
  从Derived_from_Private和Derived_from_Protected可以看出来
  1.首先Prot_Derv作为一个派生类确定了自己对于基类中数据的访问限制
    ：Prot_Derv作为一个Base的派生类，可以无视访问控制的类型，
     能够直接访问基类中的public和private字段下的数据。
    ：这些基类中的能被Prot_Derv这个点派生类访问的数据，（可能？）
     同样作为派生类中的public和private字段下的数据
  2.Port_Derv的派生类Derived_from_protected同样访问基类中的
     public和protected中的数据。
 */



int main(){
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

/*

    Base *p = &d1;      //d1的类型是Pub_Derv    ->  成功
    p = &d2;            //d2的类型是Priv_Derv   ->  失败，应为对于类的用户来说只有公有继承才可以向基类转换
    p = &d3;             //d3的类型是Prot_Derv   ->  失败，只有公有继承的用户才可以
    p = &dd1;            //dd1的类型是Derived_from_Public    ->成功，可以通过继承的类来访问
    p = &dd2;            //dd2的类型是Derived_from_Private   ->失败，私有继承，所以继承类不可以访问
    p = &dd3;            //dd3的类型是Derived_from_Protected ->失败，因为对于继承类的用户来说，

*/
    return 0;
}