#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	
	istream_iterator<int>int_it(cin);	//��cin��ȡint
	istream_iterator<int>int_eof;		//β�������
	ifstream in("afile");				//#include<fstream>
	istream_iterator<string>str_it(in); //��"afile"��ȡ�ַ���


	istream_iterator<int>in_iter(cin);	//��cin��ȡint
	istream_iterator<int>eof;			//istreamβ�������
	vector<int>vec;
	//�����õ���������ô�����ȡ��ǰһ��ֵ
	while (in_iter != eof)
		vec.push_back(*in_iter++);
	cout << "the vec value is:" << endl;
	for (auto item:vec) {
		cout << item << endl;
	}

	istream_iterator<int> in_iter(cin), eof;//��cin�ж�ȡint
	vector<int> vec(in_iter,eof);//ʹ�õ���������һ������



	return 0;
}