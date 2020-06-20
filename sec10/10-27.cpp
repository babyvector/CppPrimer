#include<iostream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
int main() {
	

	vector<int> int_container = {1,2,3,4,5,6,7,8,9,6,5,4,3,2,1};
	list<int> lst;
	sort(int_container.begin(),int_container.end());
	auto last_not_same = unique(int_container.begin(),int_container.end());
	unique_copy(int_container.begin(), last_not_same, front_inserter(lst));
	cout << "the item in lst is:" << endl;
	for (auto item : lst) {
		cout << item << endl;
	}


	return 0;
}