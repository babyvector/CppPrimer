#include<iostream>

using namespace std;

int main(){

	//�����������ε�����
 	int i = 42;
	int *p1 = &i;
	*p1 = *p1**p1;
	
	//����p1 = 42 * 42��ע�����ȼ�
	
	cout<<*p1<<endl; 


	return 0;
}
