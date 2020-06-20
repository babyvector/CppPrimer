#include<iostream>

using namespace std;

int main(){

	//叙述下面代码段的作用
 	int i = 42;
	int *p1 = &i;
	*p1 = *p1**p1;
	
	//作用p1 = 42 * 42；注意优先级
	
	cout<<*p1<<endl; 


	return 0;
}
