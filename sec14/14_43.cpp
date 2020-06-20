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
    vector<int> ivec = {12, 1024, -12, 102, 3303};
    int divider = 3;

    bool rest = !all_of(ivec.begin(), ivec.end(), bind(modulus<int>(), std::placeholders::_1, divider));
    cout<<"any of ivec can be divided? "<< rest <<endl;
}