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

	list<int>int_container = { 1,2,3,4,5,6,7,8,9,10,0,1,2,3,0,1,2,3 };
	list<int>::reverse_iterator temp_re_iterator = int_container.rbegin();
	while (temp_re_iterator != int_container.rend()) {
		if (*temp_re_iterator++ == 0) {
			temp_re_iterator--; break;
		}
	}
	if (temp_re_iterator == int_container.rend()) {
		cout << "find none" << endl;
	}
	else {
		int n = 0;
		while (temp_re_iterator != int_container.rend()) {
			temp_re_iterator++;
			n++;
		}
		cout << "find 0 in "<<n<<"th ."<< endl;
	}

	return 0;
}




