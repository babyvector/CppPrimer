#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Comparex{

public:
    bool operator()(const int& rhs, const int& lhs){
        
        return (rhs == lhs);
    }
private:

};

int main(){

    vector<int>vec = {1,2,3,4,5,6,7,8,9,7,7,6,5,4,3,32,2,10,11,12,23,7,65,4,7,7,7,7,7,7,7,8,8,8,8};
    int spec_i = 7;
    Comparex cmp;

    cout<<"the source array before replace:"<<endl;
    for(auto item : vec)
        cout<<item<<" ";
    cout<<endl;
    
    find_if(vec.begin(), vec.end(), [spec_i, &cmp](int& item){
        if( cmp(spec_i, item) )
            item = 1;
        return 0;
    });
    
    cout<<"the source array after replace:"<<endl;
    for(auto item : vec)
        cout<<item<<" ";
    cout<<endl;
    
    return 0;
}