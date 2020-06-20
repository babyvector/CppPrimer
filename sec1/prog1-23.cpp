 #include<iostream>
#include"Sales_item.h"

using namespace std;

int main(){
	Sales_item item1,item2;
	int sales_num = 1;
	if(cin>>item1){
		while(cin>>item2){
			if( item1.isbn() == item2.isbn() ){
				sales_num++;
			}else{
				cout<<item1.isbn()<<" "<<sales_num<<endl;
				item1 = item2;
				sales_num = 1;
			}
		}
		cout<<item1.isbn()<<" "<<sales_num<<endl;	
	}else{
		cout<<"error."<<endl;
	}
	/*最终的形式不够统一*/
	

	return 0;
} 
/*
	输入格式为：
	0-201-78345-X 3 20.00
	0-201-78345-X 2 25.00 
	0-202-78345-X 1 15.00
	0-202-78345-X 2 15.00
	0-203-78345-X 1 15.00
	0-204-78345-X 2 16.00
	0-205-78345-X 3 20.00
	Enter
	Ctrl+z enter ->最终出结果 
*/
 
