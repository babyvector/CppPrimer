﻿// cppprimer-11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<list>
using namespace std;
int main()
{
	map<vector<int>::iterator, int>vec_iter2int;
	map<list<int>::iterator, int>list_iter2int;
	vector<int>test_vec1;
	list<int>test_list1;
	vec_iter2int[test_vec1.begin()]++;
	list_iter2int[test_list1.begin()]++;
	
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
