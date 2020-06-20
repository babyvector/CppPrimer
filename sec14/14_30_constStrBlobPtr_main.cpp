#include "14_30_constStrBlobPtr.hpp"

int main(){

    StrBlob svec = {"test", "one", "person"};
    
    cout<<"<<test dereference StrBlobPtr>>"<<endl;
    StrBlobPtr ptr_svec(svec);
    cout<<"testing * dereference:"<<*ptr_svec<<endl;
    cout<<"testing -> dereference:"<<ptr_svec->size()<<endl;
    *ptr_svec = "test_changed";
    cout<<"change test:"<<ptr_svec->size()<<endl;

    cout<<"<<test dereference ConstStrBlobPtr>>"<<endl;
    ConstStrBlobPtr  const_ptr_svec(svec);
    cout<<"testing * dereference:"<<*const_ptr_svec<<endl;
    cout<<"testing -> dereference:"<<const_ptr_svec->size()<<endl;
    /*
        *const_ptr_svec = "test_changed_const";
        cout<<"change const test:"<<const_ptr_svec->size()<<endl;
    */

    return 0;
}