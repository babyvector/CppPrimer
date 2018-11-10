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
void elimDups(vector<string>& words){
	sort(words.begin(), words.end());
	//按照字典进行排序
	auto end_unique = unique(words.begin(), words.end());
	//end_unique返回处理过重复字符串之后的字符串数组的尾迭代器
	words.erase(end_unique, words.end());
}
void biggies(vector<string>&words,
				vector<string>::size_type&sz){
	elimDups(words);
	
	stable_sort(words.begin(), 
				words.end(), 
				//这一点需要注意的是：当参数列表是引用类型的时候，前面不加const运行时报错
				//具体原因以后探究
				[](const string& s1, const string& s2){return s1.size() < s2.size(); });

	for_each(
		find_if(words.begin(), words.end(), [sz](const string& s3){return s3.size() > sz; }), 
		words.end(), 
		[](const string &s4){cout << s4 << " "; }); 

	cout << endl;
}
int main(){
	//实现自己的elimDups
	vector<string>string_container =
	{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "title" };
	vector<string>::size_type sz = 4;
	biggies(string_container,sz);

	return 0;
}


