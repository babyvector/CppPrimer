#include<iostream>
#include"Sales_item.h"

using namespace std;

int main(){
	Sales_item item1,item2;
	cin>>item1;
	item2 = item1;
	while(cin>>item1){
		item2+=item1;
	}
	//cin>>item1>>item2;			//读取交易记录 
	cout<<item2<<endl;  	//打印他们的和 

	return 0;
} 
/*
	输入格式为：
	0-201-78345-X 3 20.00
	0-201-78345-X 2 25.00 
	Enter
	Ctrl+z enter ->最终出结果 
*/
 
