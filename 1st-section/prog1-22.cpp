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
	//cin>>item1>>item2;			//��ȡ���׼�¼ 
	cout<<item2<<endl;  	//��ӡ���ǵĺ� 

	return 0;
} 
/*
	�����ʽΪ��
	0-201-78345-X 3 20.00
	0-201-78345-X 2 25.00 
	Enter
	Ctrl+z enter ->���ճ���� 
*/
 
