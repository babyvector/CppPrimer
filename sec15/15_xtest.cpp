#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <vector>

using namespace std;

class Base{
public:
    Base() = default;
    virtual void print(){cout<<"I am base print."<<endl;};
};

class Inherit:public Base{
public:

    void print(){cout<<"I am inherit print."<<endl;}
    void additional_print(){cout<<"inherit additional_print."<<endl;}
};


int main(){
    
    vector< shared_ptr<Base*> > vec;
    Base base;
    Inherit inh;
    base.print();
    inh.print();
    Base &ref_base = base;
    Inherit &ref_inh = inh;
    vec.push_back(make_shared<Base*>(&base));
    vec.push_back(make_shared<Base*>(&inh));


    (*((vec[1]).get()))->print();
    (*((vec[1]).get()))->additional_print();

    return 0;
}