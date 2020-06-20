#include "14_26_String.hpp"
#include <algorithm>

using namespace std;

bool operator<(const String& a, const String& b){

    return (a.first_free - a.element < b.first_free - b.element);
}

bool operator==(const String& a, const String& b){

    return (a.element == b.element);
}

bool operator!=(const String& a, const String& b){

    return !(a == b);
}

ostream& operator<<(ostream& os_out, String& s){
    for_each(s.begin(), s.end(), [&](auto c){os_out<<c;});
    return os_out;
}

size_t str_len(const char* in){
    
    size_t len = 0;
    size_t i = 0;
    while(in[i] != '\0'){
        i++;
    }
    return i;
}

String::String(const char* in_char){
    size_t len = str_len(in_char);
    auto data = alloc.allocate(len + 1);

    element = data;
    first_free = element;
    cap = element + len;

    int i = 0;
    while(i++<len)
        alloc.construct(first_free++, *in_char++);
}

String::String(String&& s_mv) noexcept{
    element = s_mv.element;
    first_free = s_mv.first_free;
    cap = s_mv.cap;

    s_mv.element = nullptr;
    s_mv.first_free = nullptr;
    s_mv.cap = nullptr;

}

String& String::operator=(String&& s_mv) noexcept{
    if(this != &s_mv){
        element = s_mv.element;
        first_free = s_mv.first_free;
        cap = s_mv.cap;

        s_mv.element = nullptr;
        s_mv.first_free = nullptr;
        s_mv.cap = nullptr;

    }
    return *this;
}


char& String::operator[](size_t index){

    if(index > size())
        throw out_of_range("String [] out of range");
    else
    {
        return *(element + index);
    }
}

const char& String::operator[](size_t index) const{

    if( index > (first_free - element) )//这里如果接着用size()会出错
        throw out_of_range("String [] out of range");
    else
    {
        return *(element + index);
    }
}

void String::alloc_n_copy(const char* beg, const char* end){

}

String::String(const String& s){
    
    cout<<"invoking the copy constructor."<<endl;
    auto newdata = alloc.allocate(s.first_free - s.element + 1);
    element = newdata;
    first_free = element + (s.first_free - s.element);
    cap = first_free;
    uninitialized_copy(s.element, s.first_free, begin());

}

void String::free(){

    for_each(begin(), end(), [this](auto s){alloc.destroy(&s);});
    alloc.deallocate(element, cap - element);

}

String& String::operator=(const String& s){

    cout<<"invoking the copy= constructor."<<endl;
    auto newdata = alloc.allocate(s.first_free - s.element + 1);
    uninitialized_copy(s.element, s.first_free, newdata);
    
    free();

    element = newdata;
    first_free = element + (s.first_free - s.element);
    cap = first_free;

    return *this;
}