#include<iostream>

using namespace std;

int main(){

	//编写代码分别更改指针的值和指针所指对象的值
	int *p = NULL;
	int temp = 10;
	p = &temp;
	*p = temp+=temp; 
	
	cout<<*p<<endl;
	return 0;
}
