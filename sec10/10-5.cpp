#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;
int main(){
	
	/* 
		vector<string>container2 = {"yourname","myname","hername","hisname"};
		vector<string>container1 = {"yourname","myname","hername","hisname","allname"};
		cout<<equal(container1.cbegin(),container1.cend(),container2.cbegin())<<endl;
		这样写会出现运行错误 
	*/
	/* 
		vector<string>container1 = {"yourname","myname","hername","hisname"};
		vector<string>container2 = {"yourname","myname","hername","hisname","allname"};
		cout<<equal(container1.cbegin(),container1.cend(),container2.cbegin())<<endl;
		这样写输出结果为1 
	*/
	/* 
		vector<const char*>container1 = {"yourname","myname","hername","hisname"};
		vector<const char*>container2 = {"yourname","myname","hername","hisname","allname"};
		cout<<equal(container1.cbegin(),container1.cend(),container2.cbegin())<<endl;
		这样写输出结果为1 
	*/
	 
		vector<string>container1 = {"yourname","myname","hername","hahaname"};
		vector<string>container2 = {"yourname","myname","hername","hisname","allname"};
		cout<<equal(container1.cbegin(),container1.cend(),container2.cbegin())<<endl;
		//这样写输出结果为0


	//那些只接受一个单一迭代器来表示第二个序列的算法，都假定第二个序列至少与第一个序列一样长
	//出现以上写法的时候会出现运行错误 


	return 0;
}
