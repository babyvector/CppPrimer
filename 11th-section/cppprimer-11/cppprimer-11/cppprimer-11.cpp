// cppprimer-11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
