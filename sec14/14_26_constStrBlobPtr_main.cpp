#include "14_26_constStrBlobPtr.hpp"

int main(){

    cout<<"<<test StrBlob>>"<<endl;
    
    cout<<"test non-const version"<<endl;
    StrBlob a = {"this ", "is ", "xiaoming "};
    cout<<a[2]<<endl;
    a[2] = "XIAOMING";
    cout<<a[2]<<endl;

    cout<<"test const version"<<endl;
    const StrBlob const_a = {"that ", "is ", "xiaohua "};
    cout<<const_a[2]<<endl;
    //const_a[2] = "XIAOHUA";
    //上面一行如果不屏蔽，就会产生错误

    cout<<"<<test StrBlobPtr>>"<<endl;
    
    cout<<"test non-const version"<<endl;
    StrBlobPtr ptr_itema(a);
    cout<<ptr_itema[1]<<endl;
    ptr_itema[1] = "XIAOHUA";
    cout<<ptr_itema[1]<<endl;
    
    cout<<"test const version"<<endl;
    const StrBlobPtr const_ptr_itema(const_a);
    cout<<const_ptr_itema[1]<<endl;
    //const_ptr_itema[1] = "XIAOTAO";

    return 0;
}