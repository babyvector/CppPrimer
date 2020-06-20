#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{

    /*(a)统计大于1024的值有多少个*/
    vector<int> ivec = {12, 1024, -12, 1035, 3303};
    int num = count_if(ivec.begin(), ivec.end(), bind(greater<int>(), std::placeholders::_1, 1024));
    cout<<"num of greater than 1024 is: "<<num<<endl;
    /*(b)找到第一个不等于pooh的字符串*/
    vector<string> svec = {"pooh", "pooh", "pooh", "pooh", "poch", "pooh"};
    auto item = find_if(svec.begin(), svec.end(), bind(not_equal_to<string>(), std::placeholders::_1, "pooh"));
    cout<<"the first not_equal_to pooh string is: "<<*item<<endl;
    /*(c)将所有的值乘以2*/
    vector<int> ivec1 = {12, 1024, -12, 1035, 3303};
    transform(ivec1.begin(), ivec1.end(), ivec1.begin(), bind(multiplies<int>(), (std::placeholders::_1), 2));
    for(auto item:ivec1)
        cout<<item<<" ";
    
    cout<<endl;

}