#include<iostream>

using namespace std;

int main(){

	//解释下列代码中有没有非法定义
	int i = 0;
//	double *dp = &i;
	//取i的地址赋给dp 
	//改：地址不能够不声明的前提下进行类型转换 
//	int *ip = i;
	//让ip指向0地址 
	//改：在涉及到地址的时候不能进行类型的转换（或者由于地址变量的大小与int类型的变量的大小不一致？） 
	int *p = &i;
	//取i的地址赋给p变量
	 
	//都没有错误，都可以编译通过 
	//自己的判断完全错误
	//自己进行的实验
	double temp_test = i;
	i = temp_test;
	i = 2.9;
	 
	return 0;
}
