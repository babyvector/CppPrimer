#include<iostream>

using namespace std;

int main(){

	//��д����ֱ����ָ���ֵ��ָ����ָ�����ֵ
	int *p = NULL;
	int temp = 10;
	p = &temp;
	*p = temp+=temp; 
	
	cout<<*p<<endl;
	return 0;
}
