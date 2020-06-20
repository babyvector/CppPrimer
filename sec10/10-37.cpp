#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
#include<numeric>//->accumulate()
#include<random>//->default_random_engine
#include"Sales_item.h"

using namespace std;
int main(){


	vector<int>int_container = { 1,2,3,4,5,6,7,8,9,10,0,1,2,3,0,1,2,3 };
	list<int>list_container;
	int length_to_skip_start = int_container.size() - 7;
	int length_to_skip_end = int_container.size() - 3;
	vector<int>::reverse_iterator temp_re_container_start = int_container.rbegin();
	vector<int>::reverse_iterator temp_re_container_end = int_container.rbegin();

	temp_re_container_start += length_to_skip_start;
	temp_re_container_end += length_to_skip_end;
	while (temp_re_container_start != temp_re_container_end) {
		cout << *temp_re_container_start++ << endl;
	}
	cout << *temp_re_container_start << endl;

	return 0;
}




