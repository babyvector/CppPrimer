#include<iostream>

using namespace std;

int main(){
	
	unsigned u = 10,u2 = 42;
	cout<<u2-u<<endl;		//32
	cout<<u-u2<<endl;		//4294967264
	
	int i = 10,i2 = 42;		
	cout<<i2-i<<endl;		//32
	cout<<i-i2<<endl;		//-32
	cout<<i-u<<endl;		//0	->假设当有符号整型为正数的时候   二进制第一位为0 
	cout<<u-i<<endl;		//0
	
	//addition
	int k = -10;
	unsigned uk = k;
	cout<<uk<<endl;		//2147483648
	
	cout<<"end!"<<endl;
	
	return 0;
} 
