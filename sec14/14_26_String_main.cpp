#include "14_26_String.hpp"

int main(){

    String a("xiaoming");
    cout<<a[1]<<endl;
    a[1] = 'H';
    cout<<a<<endl;

    //don't test const version.
    return 0;
}