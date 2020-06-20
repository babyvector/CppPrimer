#ifndef _13_49_STRVEC_HPP_
#define _13_49_STRVEC_HPP_

#include <iostream>
#include <string>
#include <memory>
using namespace std;
class StrVec{

public:
    StrVec():element(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(initializer_list<string> il);
    StrVec(const StrVec& in_strVec);//拷贝
    StrVec& operator=(const StrVec& in_strVec);//拷贝复制函数

    StrVec(StrVec&&)noexcept;
    StrVec& operator=(StrVec&&)noexcept;

    int push_back(string& s);
    int reserve();
    int resize(int n);
    int size() const {return first_free - element;};
    int capacity() const {return cap - element;};
    string* begin() const{return element;};
    string* end() const{return first_free;};
    ~StrVec(){;}
private:
    allocator<string> alloc;
    pair<string*, string*>
    alloc_n_copy(const string *b, const string *e);//工具函数，被拷贝构造函数，复制运算符，和析构函数使用
    void free();
    void range_initialize(const string *first, const string *end);
    void chk_n_alloc();//被添加元素的函数使用
    void reallocate_n(size_t n);
    void reallocate();//获取更多内存并拷贝已有元素
    string* element;
    string* first_free;
    string* cap;
};
#endif
