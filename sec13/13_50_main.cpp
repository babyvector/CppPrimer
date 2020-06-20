#include <iostream>
#include <vector>

#include "13_50_update_classString.hpp"

using namespace std;

int main(){

    vector<String> sv;
    int i = 0;
    cout<<"allocate a new String."<<endl;
    String s("name");
    cout<<"push into the new String."<<endl;
    sv.push_back(std::move(s));
    cout<<"print the vector<String>."<<endl;
    for(auto item:sv)
        cout<<item<<endl;

    cout<<"print the source value which was moved."<<endl;
    cout<<s<<endl;
    
    //test vector<int> the source state after move.
    vector<int> a = {1,2,3,4,5};
    vector<int> b = std::move(a);

    
    cout<<"the b[0] value is:"<<b[0]<<endl;
    //code below will cause mistake.
    a[0] = 9;
    cout<<"the b[0] value is:"<<b[0]<<endl;
    
    cout<<"the a[0] value is:"<<a[0]<<endl;
    return 0;
}