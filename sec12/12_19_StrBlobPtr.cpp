#include "12_19_StrBlobPtr.hpp"

shared_ptr<vector<string>> StrBlobPtr::check(std::size_t i, const string &msg)const
{
	auto ret = wptr.lock();
	if(!ret)
		throw runtime_error("unbound StrBlobPtr");
	if(i >= ret->size())
		throw out_of_range(msg);
	return ret;//否则，返回指向vector的shared_ptr
}

string& StrBlobPtr::deref()const{
	
	auto data = check(curr, "deref error.");
	return (*data)[curr];

}

StrBlobPtr& StrBlobPtr::incr(){

	auto ret = this->wptr.lock();
	if(!ret){
		throw runtime_error("incr error.");
	}
	if(curr + 1 >= ret->size()){
		;
	}else{
		curr++;
	}
	return *this;
}

bool operator!=(const StrBlobPtr& ptr_a, const StrBlobPtr& ptr_b){

	bool rval = !(ptr_a.wptr.lock().get() == ptr_b.wptr.lock().get() 
				  && ptr_a.curr == ptr_b.curr);
	return rval;
}


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
StrBlobPtr StrBlob::begin(){
	return StrBlobPtr(*this);
}
		
StrBlobPtr StrBlob::end(){
	auto ret = StrBlobPtr(*this, data->size()-1);
	return ret;
}


