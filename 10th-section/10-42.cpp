#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<list>
#include<forward_list>
#include<algorithm>
#include<string>
#include<numeric>//->accumulate()
#include<random>//->default_random_engine
#include"Sales_item.h"

using namespace std;
int main(){


	
	list<string>list_container = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	list_container.sort();
	list_container.unique();
	cout << "now we print out the result." << endl;
	for (auto item:list_container) {
		cout << item << endl;

	}
	return 0;
}




