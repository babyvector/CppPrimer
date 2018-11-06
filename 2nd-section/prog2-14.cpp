#include<iostream>

using namespace std;

int main(){
	int i = 100,sum = 0;
	for(int i = 0;i != 10;++i){
		sum += i;
	}
	cout<<i<<" "<<sum<<endl;
	//最终结果：i = 10 sum = 0+1+...+9;
		//!!!自己最终回答错误:因为在for循环的时候重新定义的i将main中的i覆盖了，
		//!!!但是出了for循环之后i又变成了main中的i，也就是说覆盖只是在小的作用域中。 
	return 0;
}
