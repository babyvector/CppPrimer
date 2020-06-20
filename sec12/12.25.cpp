#include<iostream>
#include<vector>
#include<memory>
#include<string>

using namespace std;

int main(){

    int *pa = new int[10];
    delete [] pa;
    
    return 0;
}