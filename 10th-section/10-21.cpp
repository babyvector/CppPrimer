#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
using namespace std;

void test_function(){
	//引用捕获
	int init_value = 10;
	auto f = [&init_value]()->bool{if (init_value)return --init_value; else return false; };
		while (f()){
			cout << "not to zero." << endl;
		}
		cout << "the f() value is : " << f() << endl;
	
	//隐式引用捕获	
	int init_value1 = 10;
	auto g = [&]()->bool{if (init_value1)return --init_value1; else return false; };
	while (g()){
		cout << "not to zero." << endl;
	}
	cout << "the g() value is : " << g() << endl;
	
	//此时这些lambda就是相当与一个内联函数，使用起来更加方便
}

int main(){
		
	test_function();
	return 0;
}



