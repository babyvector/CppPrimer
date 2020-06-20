#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;
template<class T>
void print(T input_T){
	for (auto i : input_T)
		cout << input_T[i] << endl;
}


int main(){
	vector<int>container = {1,2,3,4,5,6,7};
	int val = 0;
	fill_n(container.begin(), container.size(), val);
	for (int i = 0; i<container.size(); i++){
		cout << container[i] << endl;
	}
	return 0;
}