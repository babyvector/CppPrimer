#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;
template<class T>
void print(T input_T){
	for (auto i : input_T)
		cout << input_T[i] << endl;
}


int main(){
	vector<int>vec;
	list<int>lst;
	int i;
	while (cin >> i)
		lst.push_back(i);
	copy(lst.cbegin(), lst.cend(), vec.begin());
	//使用copy之前vec一定要有合适的空间，否则出错
	vector<int>vec1;
	vec1.reserve(10);
	fill_n(vec1.begin(), 10, 0);
	print(vec1);
	//没有任何错误
	return 0;
}


