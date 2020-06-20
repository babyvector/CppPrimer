#include<iostream>
//using namespace std;
int main(){
	std::cout<<"/*";
	std::cout<<"*/";
	//std::cout<</* "*/" */;			//³Ë·¨´íÎó 
	std::cout<</* "*/" /* "/*" */;	//Ã»ÓÐ´íÎó 
	return 0;	
} 
