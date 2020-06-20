#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Rstring{
    friend istream& operator>>(istream& os_in, Rstring& obj_getc);
public:
    Rstring();
    Rstring(const Rstring&);
    Rstring& operator=(const Rstring&);
   
private:
    allocator<char>alloc;
    void reallocate();
    char* element;
    char* first_free;
    char* end;
    const int init_len = 10;
    
};

istream& operator>>(istream& os_in, Rstring& obj_getc){
    
    char ch;
    while( ( ch = os_in.get() ) != '\n'){
        
        if(obj_getc.first_free != obj_getc.end)
            ;
        else{
            obj_getc.reallocate();
        }
        
        obj_getc.alloc.construct(obj_getc.first_free++, ch);
    }
    *obj_getc.first_free = '\0';
    //cout<<obj_getc.element;
    return os_in;
}

void Rstring::reallocate(){

    cout<<"here we realloced."<<endl;
    auto newdata = alloc.allocate( (first_free - element) + init_len +1 );
    auto newfirst_free = newdata;

    auto data = element;
    while(data < first_free)
        alloc.construct(newfirst_free++, *data++);

    delete [] element;

    element = newdata;
    first_free = newfirst_free;
    end = element + (first_free - element) + init_len; 
}

Rstring::Rstring(){
    element = alloc.allocate(init_len+1);
    first_free = element;
    end = element + init_len;
}

Rstring::Rstring(const Rstring& s){

    //alloc
    element = alloc.allocate( s.first_free - s.element +1 );
    first_free = element;
    end = element + (s.first_free - s.element);
    //copy
    auto data = s.element;
    while(data < s.first_free)
        alloc.construct(first_free++, *data++);

}

Rstring& Rstring::operator=(const Rstring& s){

    auto newdata = alloc.allocate( (s.first_free - s.element) +1 );
    auto newfirst_free = element;

    auto data = s.element;
    while(data < s.first_free)
        alloc.construct(newfirst_free++, *data++);

    delete [] element;

    element = newdata;
    first_free = newfirst_free;
    end = element + (s.first_free - s.element);

    return *this;
}



int main(){
    Rstring s;
    cin>>s;
    Rstring b;
    cin>>b;

    while(1){}

    return 0;


}