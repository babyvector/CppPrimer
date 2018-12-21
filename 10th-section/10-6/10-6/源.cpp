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


	
	vector<int>int_vector_container ;
	vector<int>int_vector_get_container = {1,2,3};
	//istream_iterator<int>in_stream(cin);
	forward_list<int>forward_list_container;
	for (int i = 0; i < 100;i++) {
		forward_list_container.push_front(i);
		//int_vector_container.push_back(i);
		forward_list_container.push_front(i);
		forward_list_container.push_front(i);

	}


	//copy(int_vector_get_container.begin(), int_vector_get_container.end(), int_vector_container.begin());
	
	reverse(int_vector_container.begin(),int_vector_container.end());
	auto return_unique_iterator = unique(forward_list_container.begin(), forward_list_container.end());

	cout << "here we print out." << endl;
	cout << "the return_unique_iterator is :" << *return_unique_iterator << endl;
	for (auto item : forward_list_container)
		cout << item << endl;

	return 0;
}




