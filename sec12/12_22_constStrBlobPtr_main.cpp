#include <iostream>
#include <string>
#include "12_22_constStrBlobPtr.hpp"

using namespace std;


int main(){
	const StrBlob b1 = {"original"};
	string in_string;
	int i = 3;
	while(i--){
		cin>>in_string;
		b1.push_back(in_string);
	}
    ConstStrBlobPtr const_ptr(b1);
    cout<<const_ptr.deref()<<endl;
    const_ptr.incr();
    cout<<const_ptr.deref()<<endl;
    
    //const string &&test_string = std::move(const_ptr.deref());

    const_ptr.incr();
    cout<<const_ptr.deref()<<endl;
    const_ptr.incr();
    cout<<const_ptr.deref()<<endl;
    const_ptr.incr();


    StrBlob b2 = {"original"};
	auto item = b2.begin();
	while(item != b2.end()){
		cout<<item.deref();
		item.incr();
	}

	return 0;
} 
