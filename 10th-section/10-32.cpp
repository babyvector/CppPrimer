#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
#include<numeric>//->accumulate()
#include"Sales_item.h"

using namespace std;
int main(){

	vector<Sales_item>sales_item_container;
																						
	istream_iterator<Sales_item>input_istream(cin), input_eof;

	for (; input_istream != input_eof;input_istream++) {
		sales_item_container.push_back(*input_istream);
	}
	sort(sales_item_container.begin(),sales_item_container.end(), compareIsbn);

	vector<Sales_item>::iterator  merge_item=sales_item_container.begin() ;
	
	for(merge_item ; merge_item != sales_item_container.end();) {

		auto start_iterator = find_if(sales_item_container.begin(),
								      sales_item_container.end(),
			[merge_item](Sales_item  input_item) {return (input_item.isbn() == merge_item->isbn()); });
		int nums_of_iterator = count_if(sales_item_container.begin(),
										sales_item_container.end(),
			[merge_item](const Sales_item & input_item) ->bool {return (input_item.isbn() == merge_item->isbn()); });

		auto end_iterator = start_iterator + nums_of_iterator;
		
		Sales_item temp_item(merge_item->isbn());
		Sales_item return_sales_item = accumulate(start_iterator, end_iterator ,temp_item);

		merge_item = end_iterator;

		cout << return_sales_item << endl;
		
	}
	
	return 0;
}
/*输入的测试数据


	original 2 15.00
	hoking 4 22.00
	unitsstates 3 18.00
	whatisthat 1 12.50
	original 4 30.00
	hoking 4 22.00
	unitsstates 5 30.00
	whatisthat 2 25.00
	original 2 15.00
	hoking 8 44.00

*/