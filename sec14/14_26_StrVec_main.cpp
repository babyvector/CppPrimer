#include "14_26_StrVec.hpp"

int main(){

    cout<<"<<test non-const version>>"<<endl;
    StrVec test_vec = {"one", "two", "three"};
    cout<<test_vec[1]<<endl;
    test_vec[1] = "ten";
    cout<<test_vec[1]<<endl;

    cout<<"<<test const version>>"<<endl;
    const StrVec const_test_vec = {"four", "five", "six"};
    cout<<const_test_vec[1]<<endl;
    cout<<const_test_vec[4]<<endl;

    return 0;
}