#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
using namespace std;
int main(){

	istream_iterator<int>input_iterator(cin), int_eof;
	ostream_iterator<int>output_iterator(cout, "\n");
	vector<int>input_int_container;
	while (input_iterator != int_eof) {
		input_int_container.push_back(*input_iterator++);
	}
	sort(input_int_container.begin(), input_int_container.end());
	auto return_the_last_unique_position = unique(input_int_container.begin(),input_int_container.end());
 	
	unique_copy(input_int_container.begin(),return_the_last_unique_position , output_iterator);



	return 0;
}