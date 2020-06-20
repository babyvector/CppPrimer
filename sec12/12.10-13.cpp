//12.10解释下面代码
/*
    答：这种做法是不对的，这样做在运行完子函数之后会释放已经申请的空间
    改：
        process(p);
*/
/*
    12.11
    答：会发生两次delete操作

*/
/*
    12.12
    (a)process(sp)
        能够正确运行，而且运行完之后，sp指向的内存仍然存在
    (b)process(new int())
        不能正确运行，new int();错误原因：不能进行隐式的类型转换
    (c)process(p)
        不能正确运行，原因同样是因为不能发生隐式转换
    (d)process(shared_ptr<int>(p));
        能够正确运行，但是在运行完之后，p申请的内存会被释放掉

*/
/*
    12.13
    会发生二次删除内容的操作
*/
#include<iostream>
#include<string>
#include<memory>
#include<vector>

using namespace std;

void process(shared_ptr<int> ptr){
    //使用ptr

    cout<<"use_count in process:"<<ptr.use_count()<<endl;

}//ptr离开作用域,被销毁

int main(){

   //正确的使用方法如下
   shared_ptr<int> p(new int(42));//引用计数为1
   cout<<"use_count in main:"<<p.use_count()<<endl;

   process(p);//拷贝p会增加它的引用计数；在process中引用计数为2
   int i = *p;//正确：引用计数值为1

   //一下操作编译没问题，但是会造成误操作，没有按照目的释放内存
   int *x(new int(1024));
   process(shared_ptr<int>(x));
   int j = *x;
   cout<<"after released x:"<<j<<endl;



   return 0;
}

