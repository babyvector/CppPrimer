
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr{
    public:
        HasPtr(const std::string &s = std::string()):
            ps(new std::string(s)),i(0){}
        //对ps指向的string，每个HasPtr对象都有自己的拷贝
        HasPtr(const HasPtr &p):
            ps(new string(*p.ps)),i(p.i){}
        //HasPtr& operator=(const HasPtr&);
        ~HasPtr(){delete ps;}

    //private:
        std::string *ps;
        int i;
};
HasPtr& HasPtr::operator=(const HasPtr &rhs){
    auto newp = new string(*rhs.ps);//拷贝底层string
    delete ps;//释放旧内存
    ps = newp;//从右侧运算对象拷贝数据到本对象
    i = rhs.i;
    return *this;
}
//以上这段代码中要使用一个中间变量的原因是为了防止下面情况
/*
    HasPtr& HasPtr::operator=(const HasPtr &rhs){
        delete ps;//释放对象指向的string;
        //如果rhs和*this是同一个对象，我们就将从已经
        //释放的内存中拷贝数据。
        ps = new string(*(rhs.ps));
        i = rhs.i;
        return *this;
    }
    如果rhs和本对象是同一个对象，delete ps会释放*this
    和rhs指向的string。接下来，当我们在new表达式中试图
    拷贝*(rhs.ps)时，就会访问一个指向无效内存的指针，
    其行为和结果是未定义的。
*/
int main(){

    HasPtr a;
    HasPtr b = a;
    cout<<a.ps<<endl;
    cout<<b.ps<<endl;
    
    return 0;
}

