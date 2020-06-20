#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr{
    public:
        //构造函数分配新的string和新的计数器，将计数器置为1
        
        HasPtr(void){
            cout<<"void creating..."<<endl;
        
        };
        
        HasPtr(const std::string &s = string()):
            ps(new string(s)),i(0),use(new size_t(1)){
                cout<<"string creating..."<<endl;
            }
        
        //拷贝构造函数拷贝所有三个数据成员，并递增计数器
        HasPtr(const HasPtr &p):
            ps(p.ps),i(p.i),use(p.use){++*use;}
        HasPtr& operator=(const HasPtr&);
        ~HasPtr();
        string*& ref_ps(){return ps;}
        int & ref_i(){return i;}
    private:
        string *ps;
        int i;
        size_t *use;//用来记录有多少个对象共享*ps的成员

};
HasPtr::~HasPtr(){
    if(--*use == 0){//如果引用计数变为0
        delete ps;  //释放string内存
        delete use; //释放计数器内存
    }
}
HasPtr& HasPtr::operator=(const HasPtr &rhs){
    ++*rhs.use;     //递增右侧运算对象的引用计数
    if(--*use == 0){//然后递减对象的引用计数
        delete ps;  //如果没有其他用户
        delete use; //释放本地对象分配的成员
    }
    ps = rhs.ps;    //将数据从rhs拷贝到本对象
    i = rhs.i;
    use = rhs.use;
    return *this;   //返回本对象
}

int main(){

    HasPtr person1(" ");
    cout<<"after HasPtr person1()"<<endl;

    //HasPtr person2(" ");

    cout<<*person1.ref_ps()<<endl;
    
    cout<<person1.ref_i()<<endl;

    return 0;
}