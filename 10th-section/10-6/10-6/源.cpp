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
	//�����ֵ��������
	auto end_unique = unique(words.begin(), words.end());
	//end_unique���ش�����ظ��ַ���֮����ַ��������β������
	words.erase(end_unique, words.end());
}
void biggies(vector<string>&words,
				vector<string>::size_type&sz){
	elimDups(words);
	
	stable_sort(words.begin(), 
				words.end(), 
				//��һ����Ҫע����ǣ��������б����������͵�ʱ��ǰ�治��const����ʱ����
				//����ԭ���Ժ�̽��
				[](const string& s1, const string& s2){return s1.size() < s2.size(); });

	for_each(
		find_if(words.begin(), words.end(), [sz](const string& s3){return s3.size() > sz; }), 
		words.end(), 
		[](const string &s4){cout << s4 << " "; }); 

	cout << endl;
}
int main(){
	//ʵ���Լ���elimDups
	vector<string>string_container =
	{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "title" };
	vector<string>::size_type sz = 4;
	biggies(string_container,sz);

	return 0;
}


