#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;
int main(){
	
	/* 
		vector<string>container2 = {"yourname","myname","hername","hisname"};
		vector<string>container1 = {"yourname","myname","hername","hisname","allname"};
		cout<<equal(container1.cbegin(),container1.cend(),container2.cbegin())<<endl;
		����д��������д��� 
	*/
	/* 
		vector<string>container1 = {"yourname","myname","hername","hisname"};
		vector<string>container2 = {"yourname","myname","hername","hisname","allname"};
		cout<<equal(container1.cbegin(),container1.cend(),container2.cbegin())<<endl;
		����д������Ϊ1 
	*/
	/* 
		vector<const char*>container1 = {"yourname","myname","hername","hisname"};
		vector<const char*>container2 = {"yourname","myname","hername","hisname","allname"};
		cout<<equal(container1.cbegin(),container1.cend(),container2.cbegin())<<endl;
		����д������Ϊ1 
	*/
	 
		vector<string>container1 = {"yourname","myname","hername","hahaname"};
		vector<string>container2 = {"yourname","myname","hername","hisname","allname"};
		cout<<equal(container1.cbegin(),container1.cend(),container2.cbegin())<<endl;
		//����д������Ϊ0


	//��Щֻ����һ����һ����������ʾ�ڶ������е��㷨�����ٶ��ڶ��������������һ������һ����
	//��������д����ʱ���������д��� 


	return 0;
}
