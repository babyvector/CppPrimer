#include<iostream>
#include"Sales_item.h"

int main(){
	Sales_item book;
	//读入ISBN号，售出的册数以及销售价格
	std::cin>>book;
	//写入ISBN、售出册数以及销售价格
	std::cout<<book<<std::cout;
	 /*不知道为什么输出的时候有错误信息*/
	return 0;
}
