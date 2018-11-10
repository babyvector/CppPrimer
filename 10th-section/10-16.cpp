#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int test_function(int input_a){

	auto f = [input_a](int c) ->int {return input_a + c; };

	return f(5);
}

int main(){

	cout << test_function(5) << endl;
}



