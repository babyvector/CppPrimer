#include<iostream>

using namespace std;

int main(){

	/*执行代码段看生成什么结果*/
	int i,&ri = i;
	i = 5;
	ri = 10;
	cout<<i<<" "<<ri<<endl;
	//i = 10,ri = 10;
	return 0;
}
