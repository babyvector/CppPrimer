#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
#include"Sales_item.h"

using namespace std;
int main(){

	vector<Sales_item>sales_item_container{ {"original",2,15.99},{"hoking",4,20.99},{"units states",3,19.99},{"what is that",1,12.50} };
	sort(sales_item_container.begin(),sales_item_container.end(), compareIsbn);
	for (auto item : sales_item_container)
		cout << "the sorted items: "<<item.isbn() <<endl;
	


	return 0;
}