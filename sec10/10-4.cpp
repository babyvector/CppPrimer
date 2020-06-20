#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;
int main(){
	
	vector<double>v;
	for(int i = 0;i<20;i++){
		v.push_back(i);
	}
	cout<<accumulate(v.begin(),v.end(),0)<<endl;;
	return 0;
}
