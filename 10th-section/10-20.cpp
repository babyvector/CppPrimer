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


	for_each(
		stable_partition(words.begin(), words.end(), [sz](const string& s3){return s3.size() < sz; }),
		words.end(),
		[](const string &s4){cout << s4 << " "; });
	cout << endl;
	int nums_of_6words = 0;
	nums_of_6words = count_if(words.begin(), words.end(), [](const string& s4){return s4.size() > 6; });
	cout << "we have " << nums_of_6words <<" words whose length is more than 6."<< endl;
	cout << endl;
}
int main(){
	//实现自己的elimDups
	vector<string>string_container =
	{ "the", "quickly", "red", "fox", "jumps", "over", "the", "slowly", "red", "titles" };
	vector<string>::size_type sz = 5;
	biggies(string_container, sz);

	return 0;
}


//jumps quick title

