#include "14_27_constStrBlobPtr.hpp"

int main(){


    StrBlob s_vec = {"test", "one", "person"};
    StrBlobPtr ptr_s_vec(s_vec);

    cout<<ptr_s_vec.deref()<<endl;
    cout<<"test postposition ++:"<<endl;
    cout<<ptr_s_vec++.deref()<<endl;
    cout<<ptr_s_vec.deref()<<endl;

    cout<<"test preposition --"<<endl;
    cout<<(--ptr_s_vec).deref()<<endl;
    cout<<ptr_s_vec.deref()<<endl;


    return 0;
}