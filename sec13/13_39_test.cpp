#include <iostream>
#include <string>
#include "13_39_StrVec.hpp"

using namespace std;

int main(){

    StrVec sv1, sv2;
    string s1("name");

    cout<<"this is sv1"<<endl;
    int i = 11;
    while(i--){
        s1 += "name";
        sv1.push_back(s1);
        cout<<i<<endl;
    }

    sv2 = sv1;
    sv2 = sv2;
    cout<<"this is sv2."<<endl;
    auto sv2_iter = sv2.begin();
    while(sv2_iter != sv2.end()){
        cout<<*sv2_iter++<<endl;
    }

    StrVec sv3(sv1);
    cout<<"this is sv3"<<endl;
    auto sv3_iter = sv3.begin();
    while(sv3_iter != sv3.end()){
        cout<<*sv3_iter++<<endl;
    }
    
    cout<<"resize(100)"<<endl;
    sv3.resize(100);
    cout<<"sv3 after resize ,the capacity is:"<<sv3.capacity()<<endl;
    auto sv3_iter1 = sv3.begin();
    while(sv3_iter1 != sv3.end()){
        cout<<*sv3_iter1++<<endl;
    }

    sv3.reserve();
    auto sv3_iter2 = sv3.begin();
    while(sv3_iter2 != sv3.end()){
        cout<<*sv3_iter2++<<endl;
    }

    cout<<"test initializer_list init sv4:"<<endl;
    StrVec sv4({"what", "is", "your", "name"});
    auto sv4_iter = sv4.begin();
    while(sv4_iter != sv4.end()){
        cout<<*sv4_iter++<<endl;
    }

    return 0;

}