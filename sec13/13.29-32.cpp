/*
13.29.解释swap(HasPtr&, HasPtr&)中对swap的调用不会导致递归循环。
swap(lhs.ps, rhs.ps); feed the version（提供了下面的版本） : swap(std::string*, std::string*) 
and swap(lhs.i, rhs.i); feed the version（提供了下面的版本） : swap(int, int). 
Both them can't call swap(HasPtr&, HasPtr&).
Thus, the calls don't cause a recursion loop.
(自己不理解)
*/
/*
    13.30为你的类值版本的HasPtr编写swap函数，并测试它。为你的swap函数添加一个打印语句
    指出函数什么时候执行。

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
    以下的函数是抄袭的书上的
*/
class HasPtr{
    friend void swap(HasPtr&, HasPtr&);
    //首先将swap定义为friend，以便能访问HasPtr的private数据成员
    public:
        HasPtr(const std::string &s = std::string()):
            ps(new std::string(s)),i(0){}
        //对ps指向的string，每个HasPtr对象都有自己的拷贝
        HasPtr(const HasPtr &p):
            ps(new string(*p.ps)),i(p.i){}
        //HasPtr& operator=(const HasPtr&);
        HasPtr& operator=(HasPtr rhs);
        ~HasPtr(){delete ps;}
        string ret_string(){return *ps;}
        bool operator<(HasPtr& rhs){
            cout<<"we are invoking <"<<endl;
            return *ps<*rhs.ps;
        }
    private:
        std::string *ps;
        int i;
};
inline 
void swap(HasPtr& lhs, HasPtr& rhs){
    cout<<"we are invoking the swap()."<<endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);       //交换指针，而不是string数据
    swap(lhs.i, rhs.i);         //交换int成员

}
/*
    使用新的swap函数实现的赋值拷贝函数：抄袭的书上的
    注意rhs是按值传递的，意味着HasPtr的拷贝构造函数
    将右侧运算对象中的string拷贝到rhs
*/
HasPtr& HasPtr::operator=(HasPtr rhs){
    //交换左侧运算对象和局部变量rhs的内容
    swap(*this, rhs);       //rhs现在指向本对象曾经使用的内容
    return *this;           //rhs被销毁，从而delete了rhs中的指针
}

/*
HasPtr& HasPtr::operator=(const HasPtr &rhs){
    auto newp = new string(*rhs.ps);//拷贝底层string
    delete ps;//释放旧内存
    ps = newp;//从右侧运算对象拷贝数据到本对象
    i = rhs.i;
    return *this;
}
*/
/*
    13.31
    如上
    13.32
    对于类指针的HasPtr版本不会从swap中收获益处
*/


int main(){

    cout<<"hello world."<<endl;

    HasPtr a("xiaohua"),b("xiaoming");
    cout<<a.ret_string()<<endl;
    b = a;
    cout<<a.ret_string()<<endl;
    cout<<b.ret_string()<<endl;
    
    vector<HasPtr> box= {a,b,{"dahua"},{"qinghua"}};
    
    sort(box.begin(),box.end());
    /*注意：sort为什么调用类内的swap而不调用标准库中的sort还不是很清楚*/
    for(auto item:box){
        cout<<item.ret_string()<<" ";
    }
    cout<<endl;
    return 0;

}