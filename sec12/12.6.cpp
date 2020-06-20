#include<iostream>
#include<string>
#include<memory>
#include<vector>


using namespace std;
vector<int>* apply_one_vector(){
    return new vector<int>;
}
void vec_read(vector<int>&vec){
    int a = 0;
    while(cin>>a){
        vec.push_back(a);
    }
    return ;
}
void vec_print(vector<int>&vec){
    for(auto item : vec){
        cout<<item<<endl;
    }
}
int main(){

    vector<int> * int_vec = apply_one_vector();
    vec_read(*int_vec);
    vec_print(*int_vec);
    delete int_vec;
    return 0;
}