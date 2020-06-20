#include <iostream>

using namespace std;

class TestNew{
public:
    TestNew(){cout<<"we are in TestNew()"<<endl;};
};



int main(){
    cout<<"we are in btest"<<endl;
    TestNew * btest;
    cout<<"we are in test"<<endl;
    TestNew * test = new TestNew();

    return 0;
}