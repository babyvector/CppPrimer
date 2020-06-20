#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;

class StrBlob{
	public:
		typedef std::vector<std::string>::size_type size_type;
		StrBlob();
		StrBlob(std::initializer_list<std::string> il);
		size_type size() const {return data->size();}
		bool empty() const {return data->empty();}
		//添加和删除元素
		void push_back(const std::string &t)const{data->push_back(t);}
		void pop_back();
		std::string & front();
		std::string & back();
		int size();
		std::string & front()const;
		int use_count() { return data.use_count(); }
	private:
		int test_value;
		std::shared_ptr<std::vector<std::string>> data;
		//如果data[i]不合法，抛出一个异常
		void check(size_type i,const std::string &msg)const; 
};
//两个构造函数都使用初始化列表来初始化其data成员，令它指向一个动态分配的vector
//默认构造函数分配一个空vector；接收一个initializer_list的构造函数将其参数传递
//给对应的vector构造函数。此构造函数通过拷贝列表中的值来初始化vector的元素 
StrBlob::StrBlob(): data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string>il):
		 data(make_shared<vector<string>>(il)){}
void StrBlob::check(size_type i, const string &msg) const
{
	if(i >= data->size())
		throw out_of_range(msg);
}
string & StrBlob::front()
{
	//如果vector为空，check会抛出一个异常
	check(0, "front on empty StrBlob");
	return data->front();
	 
}
string & StrBlob::front() const{
	check(0,"front on empty StrBlob");
	//test_value = 1;
	return data->front() ;
}
string & StrBlob::back(){
	
	check(0,"back on empty StrBlob");
	return data->back();
	
}
void StrBlob::pop_back(){
	
	check(0,"pop_back on empty StrBlob");
	data->pop_back();
	
}
int StrBlob::size(){
	return data->size();
}

int main(){
	cout<<"test the StrBlob:"<<endl;
	StrBlob b1 = {"original"};
	cout << "the b1.size() before into {}" << b1.size() << endl;
	{
		StrBlob b2 = {"a", "an", "the"};
		cout << "b1.use_count in {}, before:" << b1.use_count() << endl;
		b1 = b2;
		b2.push_back("about");
		cout << "the b1 size is:" << b1.size() << endl;
		/*从这个引用可以看出此时b1中的vector<string>指针已经被释放了*/
		cout<<"the b2 size is:"<<b2.size()<<endl;
		cout << "b1.use_count in {}:"<<b1.use_count() << endl;
		cout <<"b2.use_count in {}:"<< b2.use_count() << endl;
	}
	cout << "b1.use_count out of {}:" << b1.use_count() << endl;

	cout<<"the b1 size is:"<<b1.size()<<endl;
	string out = b1.front();
	b1.push_back("what");
	out = b1.back();
	cout<<out<<endl;
	//最终的结果都是4 
	cout<<"hello world."<<endl;
	return 0;
} 

/*
	12.2
    可以编写出包含const版本的front和back 
	 
*/
/*
	12.3
	StrBlob需要const版本的push_back和pop_back吗？如果需要添加进去。否则解释为什么不需要
	github上的答案：如果你愿意，你当然可以这样做，但是似乎没有任何合乎逻辑的理由。编译器
	没有抱怨，因为这不会修改数据（这是一个指针），而是修改了数据指向的东西，这与使用
	const指针要求的规则完全合法。作者：David Schwartz。
	 
*/

/*
	12.4
	在我们的check函数中，没有检查i是否大于0.为什么可以忽略这个检查？
	 github上的答案：因为函数中定义的变量i是一个无符号变量。无符号数中不可能存在小于0的数。 
*/

/*
	12.5
	我们未编写接受一个initializer_list explicit参数的构造函数。讨论这个设计策略的有点和缺点。
	github上的答案：
		优点：
			编译器不会在自动转换中使用此构造函数。我们可以清楚的意识到我们使用了哪个类。
		缺点：
			我们总是使用构造函数来构造一个临时的StrBlob对象。不能使用显示构造函数的初始化的
			复制形式。不容易使用。 
	
*/ 
