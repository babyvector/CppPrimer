#include "pch.h"
#include <iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

class family {
public:
	
	map<string, vector<string>> family_container;
	void add_family( pair<string,vector<string> > input_family ) {
		family_container[input_family.first].assign(input_family.second.begin(),
													input_family.second.end());
		return;
	}
	void add_children(string family_name,string children_name) {
		family_container[family_name].push_back(children_name);
	}
	void print() {
		for (auto & item:family_container) {
			cout << "family name is:" << item.first << endl;
			int children_index = 0;
			for (auto &inner_item:item.second) {
				cout << "第" << children_index++ << "个孩子的名字是：" << inner_item << endl;
			}
		}
	}
	
};

int main()
{

	family test_family = family();
	string last_name("徐");
	vector<string>children_name{ "徐大", "徐小" };

	for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
	{		for (string cn; cout << "|-Children's names:\n", cin >> cn && cn != "@q";)
		{
			test_family.add_children(ln,cn);
		}
		//test_family.add_family(make_pair(last_name, children_name));
	}
	
	
	
	test_family.print();

}
