#include <iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<list>
using namespace std;
int main()
{
	map<string, list<int>>word_in_lines;
	string temp_word;
	int lines = 0;
	ifstream input_txt_file("words.txt");
	while (getline(input_txt_file,temp_word)) {
		word_in_lines[temp_word].push_back(lines++);
	}
	for (auto item_in_map:word_in_lines) {
		cout << item_in_map.first << ":";
		for (auto item_in_list:item_in_map.second) {
			cout << item_in_list << " ";
		}
		cout << endl;
	}
	
}