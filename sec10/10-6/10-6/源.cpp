#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
using namespace std;

void test_function(){
	//���ò���
	int init_value = 10;
	auto f = [&init_value]()->bool{if (init_value)return --init_value; else return false; };
		while (f()){
			cout << "not to zero." << endl;
		}
		cout << "the f() value is : " << f() << endl;
	
	//��ʽ���ò���	
	int init_value1 = 10;
	auto g = [&]()->bool{if (init_value1)return --init_value1; else return false; };
	while (g()){
		cout << "not to zero." << endl;
	}
	cout << "the g() value is : " << g() << endl;
	
	//��ʱ��Щlambda�����൱��һ������������ʹ���������ӷ���
}

int main(){
		
	test_function();
	return 0;
}



