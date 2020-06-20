#include "14_28_constStrBlobPtr.hpp"

int main(){


    StrBlob s_vec = {"test", "one", "person"};
    StrBlobPtr ptr_s_vec(s_vec);

    cout<<ptr_s_vec.deref()<<endl;
    cout<<"test operator +:"<<endl;
    cout<<(ptr_s_vec + 1).deref()<<endl;
    cout<<ptr_s_vec.deref()<<endl;

    cout<<"test operator - (StrBlobPtr, len):"<<endl;
    ++ptr_s_vec;
    cout<<(ptr_s_vec - 1).deref()<<endl;
    cout<<ptr_s_vec.deref()<<endl;

    cout<<"test operator - (StrBlobPtr, StrBlobPtr):"<<endl;
    StrBlobPtr rhs(ptr_s_vec);
    StrBlobPtr lhs(++ptr_s_vec);
    cout<<"lhs, rhs:"<<lhs.deref()<<","<<rhs.deref()<<endl;
    cout<<"lhs - rhs:"<<lhs - rhs<<endl;
    cout<<"rhs - lhs:"<<rhs - lhs<<endl;

    return 0;
}