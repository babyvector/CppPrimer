#include<iostream>
#include<memory>

using namespace std;


void process(shared_ptr<int> ptr){
    //使用ptr

    cout<<"use_count in process:"<<ptr.use_count()<<endl;

}//ptr离开作用域,被销毁
int main(){
    //auto p = new int( );
    auto sp = make_shared<int>();
    auto p = sp.get();
    delete p;
    
    return 0;
}