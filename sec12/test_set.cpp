#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    set<string> s_set = {"what", "is", "your", "name"};
    cout<<"we test the set[] retrun value"<<s_set["is"]<<endl;
    return 0;
}