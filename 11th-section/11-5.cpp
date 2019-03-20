#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<list>
#include<forward_list>
#include<algorithm>
#include<string>
#include<numeric>//->accumulate()
#include<random>//->default_random_engine
#include<map>
#include"Sales_item.h"

using namespace std;
void string_tolower(string& temp_string) {
	for (auto & temp_char : temp_string)
		temp_char = tolower(temp_char);
	return;
}
int main(){

	map<string, size_t>word_count;
	string temp_string;
	
	while (cin>>temp_string) {
		if (temp_string == "end")break;
		string_tolower(temp_string);
		if (temp_string.back() == '.' && temp_string.size()>1) {
			//说明是末尾带有   .    需要进行处理
			temp_string = temp_string.substr(0,temp_string.size()-1);
		}
		else { ; }
		++word_count[temp_string];
	}
	for (auto item:word_count) {
		cout << "the item " << item.first << " is: " << item.second << " " << endl;
	}
	//将拓展的string操作总结到相应的md文档中。

	
	return 0;
}




