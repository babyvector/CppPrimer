#include<iostream>
//using namespace std;
int main(){
	std::cout<<"/*";
	std::cout<<"*/";
	//std::cout<</* "*/" */;			//�˷����� 
	std::cout<</* "*/" /* "/*" */;	//û�д��� 
	return 0;	
} 
