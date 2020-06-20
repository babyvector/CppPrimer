/*
13.46:什么类型的引用可以绑定到下面的初始化器上？

int f();
vector<int> vi(100);

int&& r1 = f();
int& r2 = vi[0];
int& r3 = r1;
int&& r4 = vi[10]*f()

*/

#include <iostream>
#include <vector>

using namespace std;

int f(){}

int main(){

    vector<int> vi(100, 10);

    for(auto i : vi){
        cout<<i;
    }

    int& r0 = vi[0];
    cout<<"the vi[0] value before reference is:"<<endl;
    cout<<vi[0]<<endl;

    r0 = 99;
    cout<<"the vi[0] value after reference is:"<<endl;
    cout<<vi[0]<<endl;

    int&& r1 = f();


}