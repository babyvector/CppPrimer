#include <iostream>
#include <string>
#include <memory>

using namespace std;

class StrVec{

public:
    StrVec():element(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec& in_strVec);//拷贝
    StrVec& operator=(const StrVec& in_strVec);//拷贝复制函数
    ~StrVec();
    int push_back(const string s&);
    int reserve();
    int resize(int n);
    int size():const {return first_free - element;};
    int capacity():const {return cap - element;};
    string* begin():const{return element;};
    string* end():const{return first_free;};
private:
    allocator<string> alloc;
    alloc_n_copy();//工具函数，被拷贝构造函数，复制运算符，和析构函数使用
    free();
    chk_n_alloc();//被添加元素的函数使用
    reallocate();//获取更多内存并拷贝已有元素
    string* element;
    string* first_free;
    string* cap;
};



int main(){

    return 0;
}