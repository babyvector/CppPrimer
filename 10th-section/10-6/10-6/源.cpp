#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
#include<numeric>//->accumulate()
#include<random>//->default_random_engine
#include"Sales_item.h"

using namespace std;
int main(){

	/*
	//先生成一个里里面有100
	fstream first_input_file("first_input_file.txt",ios::out);//只有加上了ios::out才能真正的创建新的文件
	int num_of_random = 100;
	default_random_engine e;
	for (int i = 0; i < num_of_random;i++) {
		first_input_file << e() % 100<<" ";
	}
	first_input_file.close();
	*/

	fstream first_input_file("first_input_file.txt");
	fstream first_output_file("first_output_file.txt",ios::out);
	fstream second_output_file("second_output_file.txt",ios::out);

	istream_iterator<int>input_stream(first_input_file),input_eof;
	ostream_iterator<int>first_output_stream(first_output_file," "),second_output_stream(second_output_file,"\n");


	while (input_stream != input_eof) {
		
		if (*input_stream % 2)//奇数
			first_output_stream = *input_stream;
		else
			second_output_stream = *input_stream;
		input_stream++;
	}
	return 0;
}




