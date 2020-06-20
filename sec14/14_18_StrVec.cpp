#include "14_18_StrVec.hpp"
#include <algorithm>

bool operator<(const StrVec& a, const StrVec& b){

    return a.size() < b.size();
}

bool operator==(const StrVec& a, const StrVec& b){

    return a.element == b.element;
}

bool operator!=(const StrVec& a, const StrVec& b){

    return !(a == b);
}

StrVec::StrVec(initializer_list<string> il){

    cout<<"we are use ther initializer_list."<<endl;
    range_initialize(il.begin(), il.end());
}

int StrVec::push_back(const string& s){
    chk_n_alloc(); 
    alloc.construct(first_free++, s);
    return 1;
}

StrVec::StrVec(const StrVec& in_strVec){
    
    //进行拷贝
    auto data_to_copy = alloc_n_copy(in_strVec.begin(), in_strVec.end());
    element = data_to_copy.first;
    cap = first_free = data_to_copy.second;

}

StrVec& StrVec::operator=(const StrVec& in_strVec){
    //复制拷贝函数
    auto data_to_copy = alloc_n_copy(in_strVec.begin(), in_strVec.end());
    free();//为了解决自赋值问题
    element = data_to_copy.first;
    cap = first_free = data_to_copy.second;

    return *this;
}

void StrVec::range_initialize(const std::string *first, const std::string *last){

    auto newdata = alloc_n_copy(first, last);
    element = newdata.first;
    first_free = cap = newdata.second;
}

pair<string*, string*> 
StrVec::alloc_n_copy(const string *b, const string *e){

    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

/*
 *  lambda表达式的形式
 *  [capture list](parameter list) -> return type{function body}
 */
void StrVec::free(){

    if(element){
        cout<<"at free, we are going to destroy the string after moved."<<endl;
        /*
            for(auto p = first_free; p != element; ){
                
                alloc.destroy(--p);
                cout<<"is destroying."<<*p<<endl;
            }
            alloc.deallocate(element, cap - element);
        */
        for_each(element, first_free, [this](auto s){ alloc.destroy(&s); } );
        alloc.deallocate(element, cap - element);
    }
}

void StrVec::reallocate_n(size_t n){

    if( !(n > cap-element))
        return ;
    auto newdata = this->alloc.allocate(  (n + 1) );
    auto newcap = newdata + n;
    auto newfirst_free = newdata;
    //copy
    int i = 0;
    auto elem = element;
    while(i != size()){
        alloc.construct(newfirst_free++, std::move(*elem++) );
        i++;
    }
    //free
    free();
    element = newdata;
    first_free = newfirst_free;
    cap = newcap;
}
void StrVec::reallocate(){
    
    int init_length = 1;
    if(cap - element == 0){
        //第一次开辟空间
        element = this->alloc.allocate(init_length*2+1);
        first_free = element;
        cap = element + init_length*2;
    }else {
        //拓展空间

        auto newdata = this->alloc.allocate( size_t ((cap-element)*2 + 1) );
        auto newcap = newdata + (cap-element)*2;
        auto newfirst_free = newdata;
        //copy
        int i = 0;
        auto elem = element;
        while(i != size()){
            alloc.construct(newfirst_free++, std::move(*elem++) );
            i++;
        }
        //free
        free();
        element = newdata;
        first_free = newfirst_free;
        cap = newcap;
    }

}

void StrVec::chk_n_alloc(){

    if(cap - first_free >= 1){
        return;
    }else{

        reallocate();

    }
}

int StrVec::reserve(){

    auto left = element;
    auto right = first_free;
    if(element){
        while(left < right){
            string temp(*left);
            alloc.construct(left++, *--right);
            alloc.construct(right, temp);
        }
    }

    return 0;
}

int StrVec::resize(int n){

    reallocate_n(n);
    return 0;
}




