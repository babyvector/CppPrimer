#include <iostream>
#include <string>
#include "12_19_StrBlobPtr.hpp"

using namespace std;


int main(){
	StrBlob b1 = {"original"};
	string in_string;
	int i = 3;
	while(i--){
		cin>>in_string;
		b1.push_back(in_string);
	}

	auto item = b1.begin();
	auto item_b = b1.end();
	cout<<"we are derefing b1.end:"<<item_b.deref()<<endl;
	while(item != b1.end()){
		cout<<item.deref();
		item.incr();
	}
	return 0;
} 
