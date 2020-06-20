 #include<iostream>
#include"Sales_item.h"

using namespace std;

int main(){
	Sales_item total;	//保存下一条交易记录的变量
	//读入第一条交易记录，并确保有数据可以处理
	if(cin>>total){
		Sales_item trans;	//保存和的变量
		//读入并处理剩余交易记录
		while(cin>>trans){
			//如果我们仍在处理相同的书
			if(total.isbn() == trans.isbn()){
				total+=trans;	//更新销售总额 
			}else{
				//打印前一本书的结果
				cout<<total<<endl;
				total  = trans;	//total现在表示下一本书的销售额 
			}
		} 
		cout<<total<<endl;//打印最后一本书的结果 
	}else{
		//没有输入警告读者
		cerr<<"No data ?!"<<endl;
		return -1;	//表示失败 
	} 
	/*最终的形式不够统一*/
	

	return 0;
} 
/*
	输入格式为：
	0-201-78345-X 3 20.00
	0-201-78345-X 2 25.00 
	0-202-78345-X 1 15.00
	0-202-78345-X 2 15.00
	0-203-78345-X 1 15.00
	0-204-78345-X 2 16.00
	0-205-78345-X 3 20.00
	Enter
	Ctrl+z enter ->最终出结果 
*/
 
