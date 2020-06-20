#include "13_48.hpp"
#include <algorithm>

using namespace std;


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
    auto newdata = alloc.allocate(s.end() - s.begin() + 1);
    uninitialized_copy(s.begin(), s.end(), newdata);
    
    free();

    element = newdata;
    first_free = element + (s.end() - s.begin());
    cap = first_free;

    return *this;
}