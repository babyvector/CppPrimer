#include <iostream>
#include "13_44.hpp"

using namespace std;

int main(){
    String a("yourname,is very good.\n\n");
    String b("huan huan");
    String c;
    
    cout<<a;
    c = b;
    cout<<c;
    return 0;
}