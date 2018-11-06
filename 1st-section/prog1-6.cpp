 #include<iostream>
//using namespace std;
int main(){
	std::cout<<"Enter two numbers:"<<std::endl;
	int v1 = 0,v2 = 0;
	std::cin>>v1>>v2;
	std::cout<<"The mul of "<<v1;
			 <<" and "<<v2 ;
			 <<" is "<<v1*v2<<std::endl;
	return 0;	
} 
//错误原因：7，8两行多加了分号，导致<<运算符的左边没有对象，将;去除 
