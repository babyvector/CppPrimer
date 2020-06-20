#include<iostream>

using namespace std;

int main(){
	double result = 0;
	double temp = 0;
	while(cin>>temp){
		result+=temp;
	}
	cout<<"the final result is:"<<endl;
	cout<<result<<endl;
	return 0;
}
