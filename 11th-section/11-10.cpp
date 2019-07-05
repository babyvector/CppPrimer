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

/*
对于vec_iter2int[test_vec1.begin()]++;程序能正常运行
对于list_iter2int[test_list1.begin()]++;程序会报错，说"<"没定义
constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{	// apply operator< to operands
		return (_Left < _Right);
		}
	};
参考了https://github.com/Mooophy/Cpp-Primer/blob/master/ch11/ex11_9_10.cpp
*/