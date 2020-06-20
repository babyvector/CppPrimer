#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
using namespace std;
template<class T>
void print(T input_T){
	for (auto i : input_T){
		cout << i << endl;
	}
}
bool isShorter(const string& s1, const string& s2){
	return s1.size() < s2.size();
}

void elimDups(vector<string>& words){
	sort(words.begin(), words.end());
	//先按照字符的个数进行排序，相同长度的字符按照字典进行排序
	auto end_unique = unique(words.begin(), words.end());
	//end_unique返回处理过重复字符串之后的字符串数组的尾迭代器
	words.erase(end_unique, words.end());
}

int main(){
	//实现自己的elimDups
	vector<string>string_container =
	{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "title" };
	elimDups(string_container);
	stable_sort(string_container.begin(), string_container.end(), isShorter);
	print(string_container);

	return 0;
}


