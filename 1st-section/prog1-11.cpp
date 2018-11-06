#include<iostream>
//using namespace std;
int main(){
	int a,b;
	std::cin>>a>>b;
	if(a<b){
		while(a<=b){
			std::cout<<a++<<std::endl;
		}
	}else if(a>b){
		while(b<=a){
			std::cout<<b++<<std::endl;
		}
	}else{
		std::cout<<a<<std::endl;
	}
	return 0;	
} 
