#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int main() {
	
	string input_string;
	string output_string; 
	getline(cin,input_string);
	//����cin��õ�һ���ַ�������input_string
	getline(cin,output_string,'n');
	//����cin��õ�һ���ַ���n�ַ�֮ǰ��һ�ж��뵽input_string
	//ע����Ҫ��cmd������������

	cout << input_string << endl;
	cout << output_string << endl;
	system("pause");
	return 0;
}
