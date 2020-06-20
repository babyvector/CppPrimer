/*
13.1：拷贝构造函数是什么？什么时候使用它？

    拷贝构造函数，又称赋值构造函数，是一种特殊的构造函数，
    它由编译器调用来完成一些基于同一类的其他对象的构建及
    初始化。其形参必须是引用，但并不限制为const，一般普通
    的会加上const限制。此函数经常用在函数调用时用户定义类型的值传递
    及返回。拷贝构造函数要调用基类的拷贝构造函数和成员函数。
    如果可以的话，它将用常量方式调用，另外，也可以用非常量方式调用。

    使用的地方:

    1. 一个对象作为函数参数，以值传递的方式传入函数体
    2. 一个对象作为函数返回值，以值传递的方式从函数返回
    3. 一个对象用于给另外一个对象进行初始化(常称为赋值初始化)


13.2 解释为什么下面的声明是非法的：

    Sales_data::Sales_data(Sales_data rhs);

    拷贝构造函数的形参类型必须为引用类型，因为非引用类型的形参
    在使用过程会调用拷贝构造函数

13.3 当我们拷贝一个StrBlob时，会发生什么？拷贝一个StrBlobPtr呢？

13.4 

    Point global;
    Point foo_bar(Point arg){//1
        Point local = arg, *heap = new Point(global);
        *heap = local;
        Point pa[ 4 ] = {local, *heap};
        return *heap;
    }

    #include<iostream>
    using namespace std;

    class Point{

    public:

        Point(){
            cout<<"we invoke the create function."<<endl;
        };
        Point(Point & obj){
            this->value = obj.value;
            cout<<"we invoke copy function."<<endl;
        }
        Point foo_bar(Point arg){//这里有一次调用copy function
            cout<<"now we are in foo_bar."<<endl;
            Point global;
            cout<<"line 1"<<endl;
            Point local = arg, *heap = new Point(global);//这里有两次调用copy function
            cout<<"line 2"<<endl;
            *heap = local;
            cout<<"line 3"<<endl;
            Point pa[ 4 ] = {local, *heap};//这里有两次调用copy function，并且有两次调用create function
            cout<<"line 4"<<endl;
            return *heap;//这里有依次调用copy function
        }
        
    private:
        int value;
    };

    int main(){
        Point global,env;
        global.foo_bar(env);
        return 0;
    }

13.5 给定下面的类框架，编写一个拷贝构造函数，拷贝所有的成员。
     你的构造函数应该动态分配一个新的string，并将对象拷贝到
     ps指向的位置，而不是ps本身的位置。

     class HasPtr{
         public:
            HasPtr(const std::string &s = std::string()):
                ps(new std::string(s),i(0)){}
         private:
            std::string *ps;
            int i;
     }
    //整个能够运行的程序如下：
    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;


    class HasPtr{
        public:
        HasPtr(const std::string &s = std::string()):
                ps(new std::string(s)),i(0){
                    cout<<"we are at create function."<<endl;
                }
        HasPtr(HasPtr & obj){
            //if(ps != NULL)delete ps;
            this->ps = new string( *obj.ps );
                cout<<"we are use copy function."<<endl;
        }

        //private:
        string* ps;
        int i;
        ~HasPtr(){
            if( ps != NULL )delete ps;
            cout<<"we are at destory."<<endl;
        }
    };

    int main(){
        HasPtr tmp;
        cout<<*tmp.ps<<endl;
        HasPtr new_tmp("hello");
        HasPtr newer_tmp = new_tmp;
        tmp = new_tmp;
        cout<<*new_tmp.ps<<endl;
        cout<<*tmp.ps<<endl;
        cout<<*newer_tmp.ps<<endl;
        //HasPtr ;
        return 0;
    }

13.9 析构函数是什么？合成析构函数完成什么工作？什么时候会生成合成析构函数？
    
     析构函数是一个成员函数，其类名以波浪号为前缀。

     与任何复制构造函数和赋值运算符一样，对于某些类，定义了合成的析构函数
     定义了合成的析构函数以禁止删除该类型的对象。否则合成的析构函数的函数
     体为空。

     编译器为任何未定义自己的析构函数的类定义一个合成的析构函数。

13.10 当一个StrBlob对象销毁时发生什么？一个StrBlobPtr对象销毁时呢？

     【注意：】
     当StrBlob对象被破坏时，动态对象的use_count会减少。如果没有，如果没有
     指针指向share_ptr指向那个动态对象，那个动态对象将会被释放。

     当一个StrBlobPter对象被销毁了，它所指向的动态内存不会被释放。

13.11 为前面练习中HasPtr类添加一个析构函数。

    前面已经做过

13.12 在下面的代码片段中会发生几次析构函数调用？

    bool fcn(const Sales_data *trans, Sales_data accum){
        Sales_data item1(*trans),item2(accum);
    }

    看的网上的解答：一共调用了三次，
        分别是：accum,item1,item2.

13.13 理解拷贝控制成员和构造函数的一个好方法是定义一个简单的类，为该类定义
    这些成员，每个成员都打印出自己的名字：
    struct X{
        X(){cout<<"X()"<<endl;}
        X(const X&){cout<<"X(const X&)"<<endl;}
    };
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct X{
    public:
        X(){cout<<"X()"<<endl;}
        X(const X&){cout<<"X(const X&)"<<endl;}
        X& operator=(const X& obj){
            cout<<"X& operator=(const X& obj)"<<endl;
            length = obj.length;
            name = obj.name;
            return *this;
        } 
        ~X(){
            cout<<"~X()"<<endl;        
        }
    private:
        int length;
        string name;
    };
void use_x(const X){
    cout<<"we are at use_x"<<endl;
}
void use_xr(const X&){
    cout<<"we are at use_xr"<<endl;
}
int main(){

    //作为非引用和引用传递
    /*
    X a;
    use_x(a);
    use_xr(a);
    */
    //动态分配它们
    /*
    X* b = new X();
    use_x(*b);
    use_xr(*b);  
    */
   //放入容器中
   X c,d,e,f,g;
   vector<X> X_vector;
   X_vector.reserve(5);//这个点不可少，不然就会出现改变容器大小之后再进行相应的操作
   cout<<"push c"<<endl;
   X_vector.push_back(c);
   cout<<"X_vector.size()"<<X_vector.size()<<endl;
   cout<<"push d"<<endl;
   X_vector.push_back(d);
   cout<<"X_vector.size()"<<X_vector.size()<<endl;
   cout<<"push e"<<endl;
   X_vector.push_back(e);
   cout<<"X_vector.size()"<<X_vector.size()<<endl;
   cout<<"push f"<<endl;
   X_vector.push_back(f);
   cout<<"X_vector.size()"<<X_vector.size()<<endl;
   cout<<"push g"<<endl;
   X_vector.push_back(g);
   cout<<"X_vector.size()"<<X_vector.size()<<endl;
   
   cout<<"next we get into {}"<<endl;
   {X_vector;}
   cout<<"we get out of X_vector"<<endl;
    return 0;
}


















