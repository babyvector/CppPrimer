#include "14_32_StrBlobManager.hpp"

int main(){

    StrBlob svec = {"this", "isa", "test"};
    StrBlobPtr ptr_svec(svec);
    StrBlobManager manager(ptr_svec); 
    cout<<manager->size()<<endl;

    return 0;
}