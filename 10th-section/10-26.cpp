/*
10.26 解释三种迭代器的不同之处？

1. back_inserter      创建一个使用push_back的迭代器
2. front_inserter	  创建一个使用push_front的迭代器
3. inserter			  创建一个使用insert的迭代器
					 （insert是将一个元素插入到指定元素之前）
*/

#include<iterator>
#include<vector>
#include<list>
using namespace std;
int main() {
	
	list<int> lst = {1,2,3,4};
	list<int> lst2, lst3;

	copy(lst.cbegin(),lst.cend(),front_inserter(lst2));
	copy(lst.cbegin(),lst.cend(),inserter(lst3,lst3.begin()));

	cout << "lst" << endl;
	for (auto item : lst) {
		cout << item << endl;
	}
	cout << "lst2" << endl;
	for (auto item : lst2) {
		cout << item << endl;
	}
	cout << "lst3" << endl;
	for (auto item : lst3) {
		cout << item << endl;
	}
	return 0;
}
//其中inserter接收两个参数后一个参数可以决定插入的位置
//但是另外两个本来就是代表生成插入头部和插入尾部的迭代器
//返回的插入迭代器，是可以直接使用而不再使用相关的函数进行插入操作这样更加简单
