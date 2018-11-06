#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>

using namespace std;
int main(){
	vector<string>string_container = {"hello","yourname","i ","want","to know","yourname"};
	string comp_string = "yourname";
	list<string>string_list;
	for(int i = 0;i<string_container.size();i++){
		string_list.push_back(string_container[i]);
	}
	cout<<count(string_list.begin(),string_list.end(),comp_string)<<endl;
	
	return 0;
}
