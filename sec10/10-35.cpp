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
	vector<int>::iterator temp_iterator = int_container.end();
	while (temp_iterator != int_container.begin()) {
		cout << *--temp_iterator << endl;
	}


	return 0;
}




