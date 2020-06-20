#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
	
	vector<int>container;
	int comp_word = 11;
	for(int j = 0;j<20;j++)
	for(int i = 0;i<20;i++){
		container.push_back(i);
	}
	cout<<count(container.begin(),container.end(),comp_word);
	cout<<endl;
	return 0;
}
