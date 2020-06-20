#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool divide(const string& input_string){
	return input_string.size() < 5;
	//true的值会排在容器的前部分
}
int main(){

	vector<string>string_container = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "titles" };

	auto middle_node = partition(string_container.begin(),string_container.end(),divide);
	for (middle_node; middle_node < string_container.end(); middle_node++){
		cout << *middle_node << endl;
	}
	return 0;
}
