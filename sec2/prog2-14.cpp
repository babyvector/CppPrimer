#include<iostream>

using namespace std;

int main(){
	int i = 100,sum = 0;
	for(int i = 0;i != 10;++i){
		sum += i;
	}
	cout<<i<<" "<<sum<<endl;
	//���ս����i = 10 sum = 0+1+...+9;
		//!!!�Լ����ջش����:��Ϊ��forѭ����ʱ�����¶����i��main�е�i�����ˣ�
		//!!!���ǳ���forѭ��֮��i�ֱ����main�е�i��Ҳ����˵����ֻ����С���������С� 
	return 0;
}
