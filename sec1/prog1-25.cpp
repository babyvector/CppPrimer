 #include<iostream>
#include"Sales_item.h"

using namespace std;

int main(){
	Sales_item total;	//������һ�����׼�¼�ı���
	//�����һ�����׼�¼����ȷ�������ݿ��Դ���
	if(cin>>total){
		Sales_item trans;	//����͵ı���
		//���벢����ʣ�ཻ�׼�¼
		while(cin>>trans){
			//����������ڴ�����ͬ����
			if(total.isbn() == trans.isbn()){
				total+=trans;	//���������ܶ� 
			}else{
				//��ӡǰһ����Ľ��
				cout<<total<<endl;
				total  = trans;	//total���ڱ�ʾ��һ��������۶� 
			}
		} 
		cout<<total<<endl;//��ӡ���һ����Ľ�� 
	}else{
		//û�����뾯�����
		cerr<<"No data ?!"<<endl;
		return -1;	//��ʾʧ�� 
	} 
	/*���յ���ʽ����ͳһ*/
	

	return 0;
} 
/*
	�����ʽΪ��
	0-201-78345-X 3 20.00
	0-201-78345-X 2 25.00 
	0-202-78345-X 1 15.00
	0-202-78345-X 2 15.00
	0-203-78345-X 1 15.00
	0-204-78345-X 2 16.00
	0-205-78345-X 3 20.00
	Enter
	Ctrl+z enter ->���ճ���� 
*/
 
