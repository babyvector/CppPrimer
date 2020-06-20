/*
	12.16
	如果你试图拷贝或赋值unique_ptr，编译器并不总是能给出易于理解的错误信息。编写包含这种
	错误的程序，观察编译器如何诊断这种错误。

	在我们使用了拷贝函数，和拷贝赋值运算符的时候编译器会提示我们使用的函数已经被删除了。
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;

	12.17
	下面的unique_ptr声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪里？
	int ix = 1024, *pi = &ix,*pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	IntP p0(ix);
	IntP p1(pi);
	IntP p2(pi2);
	IntP p3(&ix);
	IntP p4(new int(2048));
	IntP p5(p2.get());
	答：除了第一个类型使用错误之外其余的全部使用恰当。
	12.18
	为什么shared_ptr中没有release成员？
	答：因为因为shared_ptr指向的内容是shared的如果但方面的release掉，其他指向这块内存的会出错。


*/

#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main() {

	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	/*
	//IntP p0(ix);                  //can't compile
	{
		cout << "IntP p1(pi)" << endl;
		IntP p1(pi);                    //no error
	}
	
	{
		cout << "IntP p2(pi2)" << endl;
		{
			{IntP p2(pi2); }                   //no error
		}
		*pi2 = 1000;
	
	}
	*pi2 = 90;

	{
		cout << "IntP p3(&ix)" << endl;
		IntP p3(&ix);                   //no error
	}
	
	{
		cout << "IntP p4(new int(2048))" << endl;
		IntP p4(new int(2048));         //no error
	}
	
	{
		cout << "IntP p5(p2.get())" << endl;
		IntP p2(new int(555));
		IntP p5(p2.get());              //error because we 
		cout << "the p5:";
		cout << *p5 << endl;
	}
	*/
	cout << "we all finished all test." << endl;


	/*
	cout<<"here we test the unique_ptr can't copy and ="<<endl;
	unique_ptr<string> ps1(new string("steosaurus"));
	unique_ptr<string> ps2(ps1);    //this is one error
	unique_ptr<string> ps3;         //this is one error unique means all to one.
	ps3 = ps2;
	*/

	return 0;
}

