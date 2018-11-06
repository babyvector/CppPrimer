#include<iostream>
//using namespace std;
int main(){
	int a = 50;
	int result = 0;
	while(a<=100){
		result+=a++;
	}
	std::cout<<"the result is:"<<result<<std::endl;
	return 0;	
} 
