#include<iostream>

using namespace std;

int main(){
	
	//下列中定义不合法的是
	int ival = 1.01;
	//不合法，int对double 
	//改：虽然不合法但是最终能够编译通过，而且能够进行引用，但是最终的结果是1 
	int &rval1 = 1.01;
	//不合法，非常量引用不能引用常量 
	int &rval2 = ival;
	//ival不合法 
	//改：虽然不合法但是能够编译通过 
	int &rval3;
	//引用必须初始化。 
	 
	
	return 0;
} 
