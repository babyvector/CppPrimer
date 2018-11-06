#include<iostream>

using namespace std;

int main(){

	int i = 0, &r1 = i;
	double d = 0, &r2 = d;

	r2 = 3.14159;
	r2 = r1;
	//编译不通过，类型不匹配 
	//改：编译通过
	i = r2;
	//编译不通过，类型不匹配 
	//改：编译通过
	r1 = d;
	//	编译不通过，类型不匹配 
	//改：编译通过
	
	///总结：之所以这些操作都能够实现是因为=相当于类型转换
	///就算是使用引用进行赋值也是相当于直接拿某个变量进行复制
	///而赋值的过程中，int型变量去读写double型变量的时候也是将小数精度部分略掉了，但是仍然可行。
	
	cout << r2 << endl;
	cout << i << endl;
	cout << r1 << endl;
	cout << d << endl;

	return 0;
}
