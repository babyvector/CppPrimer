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
	
	cout << _is_empty(s) << endl;;//is_empty()�������������ʹ�ã���Ϊϵͳ����ʹ������������ĺ��� 

	return 0;
}
//6.18
//(a)
bool compare(matrix & a,matrix & b);
//(b)
vector<int>::iterator change_val(int,vector<int>::iterator &);//iterator���Ӣ�ĵ��ʲ���д 
//6.19
//a���ò��Ϸ�
//b���úϷ� 
//c���úϷ� 
//d���úϷ� 
//6.20 
//�������÷�����һ������ֻ�ǵ����������ݶ������������޸ĺ󷵻�
//���������ø�Ϊ�������õ�ʱ��ᷢ�����������Ϊ���ʹ��� 

