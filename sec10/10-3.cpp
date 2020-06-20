#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;
int main(){
	
	vector<int>int_container;
	for(int i = 0;i<20;i++){
		int_container.push_back(i);
	}
	cout<<accumulate(int_container.begin(),int_container.end(),0)<<endl;;
	return 0;
}
