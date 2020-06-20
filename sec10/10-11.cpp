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
	//�Ȱ����ַ��ĸ�������������ͬ���ȵ��ַ������ֵ��������
	auto end_unique = unique(words.begin(), words.end());
	//end_unique���ش�����ظ��ַ���֮����ַ��������β������
	words.erase(end_unique, words.end());
}

int main(){
	//ʵ���Լ���elimDups
	vector<string>string_container =
	{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "title" };
	elimDups(string_container);
	stable_sort(string_container.begin(), string_container.end(), isShorter);
	print(string_container);

	return 0;
}


