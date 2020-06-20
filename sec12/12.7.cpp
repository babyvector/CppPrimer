#include<iostream>
#include<string>
#include<memory>
#include<vector>


using namespace std;
shared_ptr< vector<int> > apply_one_vector(){
    return make_shared< vector<int> >();
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

    shared_ptr<vector<int> > int_vec = apply_one_vector();
    cout<<"int_vec use_count is:"<<int_vec.use_count()<<endl;
    vec_read(*int_vec);
    cout<<"int_vec use_count is:"<<int_vec.use_count()<<endl;
    shared_ptr<vector<int> > int_vec_b = int_vec;
    vec_print(*int_vec);
    cout<<"int_vec use_count is:"<<int_vec.use_count()<<endl;
    
    return 0;
}