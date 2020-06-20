//解释下列代码中为什么p合法而lp非法
#include<iostream>

using namespace std;

int main(){
	int i = 42;
	void *p = &i;
	long *lp = &i;
	
	
	return 0;
} 
