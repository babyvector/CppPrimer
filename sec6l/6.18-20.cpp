#include<iostream>
using namespace std;

bool _is_empty( string & s){

	return s.empty();
	
}
bool is_there_captial_word(const string&s){

	int i = 0;
	while(i<s.length()&&(s[i]>='a'&&s[i]<='z')){
		i++;
	}
	if(i == s.length()){
		return true;
	}else{
	
		return false;
	}
} 
string lowercase(string&s){
	for(int i = 0;i<s.length();i++){
		if(s[i]<'a'){
			s[i] = s[i]+('a'-'A');
		}
	}
	return s;
}
int main(){

	string s = "abceEFG";
	const string ss = "abcdefgHIGK";
	cout<<is_there_captial_word(ss)<<endl;
	cout<<lowercase(s)<<endl;
	
	cout << _is_empty(s) << endl;;//is_empty()这个函数名不能使用，因为系统中有使用这个函数名的函数 

	return 0;
}
//6.18
//(a)
bool compare(matrix & a,matrix & b);
//(b)
vector<int>::iterator change_val(int,vector<int>::iterator &);//iterator这个英文单词不会写 
//6.19
//a调用不合法
//b调用合法 
//c调用合法 
//d调用合法 
//6.20 
//常量引用发生在一个函数只是调用了其内容而不会对齐进行修改后返回
//将常量引用改为变量引用的时候会发生编译错误因为类型错误 

