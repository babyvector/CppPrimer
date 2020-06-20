#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
#include<functional>
using namespace std;
using namespace std::placeholders;

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

bool checkSize(string&input_string,int sz) {
	
	return input_string.length() > sz;
}


void biggies(vector<string>&words,vector<string>::size_type&sz) {

	elimDups(words);

	for_each(
		partition(words.begin(), words.end(), bind(checkSize,_1,sz)),
		words.end(),
		[](const string &s4) {cout << s4 << " "; });
	cout << endl;

}

int main() {
	//实现自己的elimDups
	vector<string>string_container =
	{ "the", "quickly", "red", "fox", "jumps", "over", "the", "slowly", "red", "titles" };
	vector<string>::size_type sz = 5;
	biggies(string_container, sz);

	return 0;
}


//jumps quick title

