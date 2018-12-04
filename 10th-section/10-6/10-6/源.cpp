#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
#include<functional>

using namespace std;
using namespace std ::placeholders;
template<class T>
void print(T input_T) {
	for (auto i : input_T) {
		cout << i << endl;
	}
}
void elimDups(vector<string>& words) {
	sort(words.begin(), words.end());
	//按照字典进行排序
	auto end_unique = unique(words.begin(), words.end());
	//end_unique返回处理过重复字符串之后的字符串数组的尾迭代器
	words.erase(end_unique, words.end());
}
bool checkSize(string&input_string , unsigned int sz) {
	return input_string.length() < sz;
}
void find_first(int nun_in_vector) {
	
	return ;
}
int main(){
	//实现自己的elimDups
	string temp_string = "Name";
	vector<unsigned int>int_container = { 1,2,3,4,5,6,7,8,9,10 };
	
	auto find_fisrt = bind(checkSize,temp_string,_1);

	for (unsigned int i = 0; i < int_container.size();i++) {
		if (find_fisrt(int_container[i]) ) {
			cout << "the first bigger than the length of string temp_string is " << i << endl;
			break;
		}
	}
	return 0;
}


//jumps quick title

