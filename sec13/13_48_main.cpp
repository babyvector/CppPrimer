#include <iostream>
#include <vector>
#include "13_48.hpp"

using namespace std;

int main(){

    vector<String> sv;
    int i = 0;
    String s("name");
    while(i++ < 3)
        sv.push_back("your");
    for(auto item:sv)
        cout<<item<<endl;

    return 0;
}