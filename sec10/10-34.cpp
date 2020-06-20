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

	vector<int>int_container = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int>::reverse_iterator temp_re_iterator = int_container.rbegin();
	while (temp_re_iterator != int_container.rend()) {
		cout << *temp_re_iterator++ << endl;
	}


	return 0;
}




