#include<iostream>

using namespace std;

int main(){

	/*ִ�д���ο�����ʲô���*/
	int i,&ri = i;
	i = 5;
	ri = 10;
	cout<<i<<" "<<ri<<endl;
	//i = 10,ri = 10;
	return 0;
}
