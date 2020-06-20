#include<iostream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
int main() {
	

	vector<int> int_container = {1,2,3,4,5,6,7,8,9};
	vector<int> get_items_from_int_container1,
				get_items_from_int_container3;
	list<int>	get_items_from_int_container2;
	copy(int_container.begin(),int_container.end(),
		 back_inserter(get_items_from_int_container1));
	//1 2 ...
	copy(int_container.begin(), int_container.end(),
		 front_inserter(get_items_from_int_container2));
	//9 8 ...
	copy(int_container.begin(), int_container.end(),
		 inserter(get_items_from_int_container3,get_items_from_int_container3.begin()));
	//9 8 ... //最后一个预测错误，注意书上的358页
	//输出
	cout << "get_items_from_int_container1" << endl;
	for (auto item:get_items_from_int_container1) {
		cout << item << endl;
	}
	cout << "get_items_from_int_container2" << endl;
	for (auto item : get_items_from_int_container2) {
		cout << item << endl;
	}
	cout << "get_items_from_int_container3" << endl;
	for (auto item : get_items_from_int_container3) {
		cout << item << endl;
	}

	return 0;
}