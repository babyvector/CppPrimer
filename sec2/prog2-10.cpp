#include<iostream>

using namespace std;

string global_str;
int global_int;


void write(){
	int local_int;
	string local_str;
	
	cout<<local_int<<endl;
	cout<<local_str<<endl;
	
}
int main(){

	int local_int;
	string local_str;
	
	cout<<global_str<<endl;
	cout<<global_int<<endl;
	cout<<local_int<<endl;
	cout<<local_str<<endl;
	cout<<"in the function"<<endl;
	write(); 
	
	return 0;
}
