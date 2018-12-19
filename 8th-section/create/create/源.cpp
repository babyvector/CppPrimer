#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int main() {
	
	string input_string;
	string output_string; 
	getline(cin,input_string);
	//将从cin获得的一行字符串读入input_string
	getline(cin,output_string,'n');
	//将从cin获得的一行字符，n字符之前的一行读入到input_string
	//注意需要从cmd框中输入两次

	cout << input_string << endl;
	cout << output_string << endl;
	system("pause");
	return 0;
}
