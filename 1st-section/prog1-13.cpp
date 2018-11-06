#include<iostream>

using namespace std;

int main(){
	int result = 0 ;
	for(int i = 50;i<=100;i++){
		result+=i;
	}
	cout<<"the result is:"<<result<<endl;
	for(int i = 10;i>=0;i--){
		cout<<"i:"<<i<<endl;
	}
	int a,b;
	cin>>a>>b;
	cin.ignore();
	int min,max;
	if(a>=b){
		min = b;
		max = a;
	}else{
		min = a;
		max = b;
	}
	cout<<"两整数范围内的所有数："<<endl;
	for(int i = min;i<=max;i++){
		cout<<i<<endl;
	}
} 
