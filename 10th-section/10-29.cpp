#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
using namespace std;
int main() {

	fstream file("temp_file.txt");

	string temp_string;
	string temp_string1;
	getline(file,temp_string);
	getline(file,temp_string1);

	cout << "the temp_string is : " << temp_string << endl;
	cout << "the temp_string1 is : " << temp_string1 << endl;
	file.close();
	file.open("temp_file.txt");
	istream_iterator<string> file_string_iterator(file),nexeof;
	
	
	vector<string>string_container;
	
	while (file_string_iterator != nexeof) {
		string_container.push_back(*file_string_iterator++);
	}

	cout << "the item is: " << endl;
	for (auto item:string_container) {
		cout << item << endl;
	}

	return 0;
}