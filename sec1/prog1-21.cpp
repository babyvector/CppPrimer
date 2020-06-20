#include<iostream>
#include"Sales_item.h"

using namespace std;

int main(){
	Sales_item item1,item2;
	cin>>item1>>item2;			//读取交易记录 
	cout<<item1+item2<<endl;  	//打印他们的和 
	return 0;
} 
