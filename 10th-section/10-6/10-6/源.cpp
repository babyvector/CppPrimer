#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	
	istream_iterator<int>int_it(cin);	//从cin读取int
	istream_iterator<int>int_eof;		//尾后迭代器
	ifstream in("afile");				//#include<fstream>
	istream_iterator<string>str_it(in); //从"afile"读取字符串


	istream_iterator<int>in_iter(cin);	//从cin读取int
	istream_iterator<int>eof;			//istream尾后迭代器
	vector<int>vec;
	//解引用迭代器，获得从流读取的前一个值
	while (in_iter != eof)
		vec.push_back(*in_iter++);
	cout << "the vec value is:" << endl;
	for (auto item:vec) {
		cout << item << endl;
	}

	istream_iterator<int> in_iter(cin), eof;//从cin中读取int
	vector<int> vec(in_iter,eof);//使用迭代器构造一个容器



	return 0;
}