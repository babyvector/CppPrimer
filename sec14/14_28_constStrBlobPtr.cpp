#include "14_28_constStrBlobPtr.hpp"

/* 以下都是StrBlobPtr的函数*/
bool operator==(const StrBlobPtr& a, const StrBlobPtr& b)
{

	return !(a != b);
}

bool operator!=(const StrBlobPtr& ptr_a, const StrBlobPtr& ptr_b)
{

	bool rval = !(ptr_a.wptr.lock().get() == ptr_b.wptr.lock().get() 
				  && ptr_a.curr == ptr_b.curr);

    return ptr_a.curr != ptr_b.curr;
}

StrBlobPtr StrBlobPtr::operator+(const size_t len)
const
{
	StrBlobPtr ret(*this);
	ret += len;
	return ret;
}

StrBlobPtr StrBlobPtr::operator-(const size_t len)
const
{
	StrBlobPtr ret(*this);
	ret -= len;
	return ret;
}

size_t operator-(StrBlobPtr&lhs, StrBlobPtr&rhs)
{
	return lhs.curr - rhs.curr;
}

const string& StrBlobPtr::operator[](size_t index) 
const
{
	return (*wptr.lock())[index];
}

string& StrBlobPtr::operator[](size_t index)
{
	return (*wptr.lock())[index];
}

StrBlobPtr& StrBlobPtr::operator+=(const size_t len)
{
	check(curr + len, "operator+ out of range.");
	curr += len;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator-=(const size_t len)
{
	check(curr - len,"operator-= out of range");
	curr -= len;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr + 1, "operator ++ out of range.");
	++curr;
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
	StrBlobPtr ret(*this);
	++*this;
	return ret;
}
StrBlobPtr& StrBlobPtr::operator--()
{
	check(curr - 1, "operator -- out of range.");
	--curr;
	return *this;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr ret(*this);
	--*this;
	return ret;
}

string& StrBlobPtr::deref()
{
	auto data = check(curr, "deref error.");
	return (*data)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	auto ret = this->wptr.lock();
	if(!ret){
		throw runtime_error("incr error.");
	}
    if(curr < ret->size()){
        curr++;
    }
	
	return *this;
}

shared_ptr<vector<string>> 
StrBlobPtr::check(std::size_t i, const string &msg)
const
{
	auto ret = wptr.lock();
	if(!ret)
		throw runtime_error("unbound StrBlobPtr");
	if(i >= ret->size())
		throw out_of_range(msg);
	return ret;//否则，返回指向vector的shared_ptr
}

bool operator<(const StrBlob& a, const StrBlob& b)
{
	return (a.size() < b.size());
}


/* 以下都是ConstStrBlobPtr中的代码 */
shared_ptr<vector<string>> 
ConstStrBlobPtr::check(std::size_t i, const string &msg)const
{
	auto ret = wptr.lock();
	if(!ret)
		throw runtime_error("unbound StrBlobPtr");
	if(i >= ret->size())
		throw out_of_range(msg);
	return ret;//否则，返回指向vector的shared_ptr
}
	
const string& ConstStrBlobPtr::deref()
const
{
	auto data = check(curr, "deref error.");
	return (*data)[curr];

}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
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


/* 以下是StrBlob的代码 */

StrBlob::StrBlob(): data(make_shared<vector<string>>()){}

StrBlob::StrBlob(initializer_list<string>il):
		 data(make_shared<vector<string>>(il)){}

const string& StrBlob::operator[](size_t index) 
const
{
	cout<<"invoking the const version"<<endl;
	return (*data)[index];
}

string& StrBlob::operator[](size_t index)
{
	cout<<"invoking the non-const version"<<endl;
	return (*data)[index];
}

bool operator==(const StrBlob& a, const StrBlob& b)
{
	return a.data.get() == b.data.get();
}

bool operator!=(const StrBlob& a, const StrBlob& b)
{
	return !(a == b);
}

void StrBlob::check(size_type i, const string &msg) 
const
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

string & StrBlob::front() 
const
{
	check(0,"front on empty StrBlob");
	//test_value = 1;
	return data->front() ;
}

string & StrBlob::back()
{
	check(0,"back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0,"pop_back on empty StrBlob");
	data->pop_back();
}

StrBlobPtr StrBlob::begin() 
const
{
	//注意这里返回的*this是const类型的
	return StrBlobPtr(*this);
}

	
StrBlobPtr StrBlob::end() 
const
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

ConstStrBlobPtr StrBlob::cbegin() 
const
{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() 
const
{
    return ConstStrBlobPtr(*this,data->size());
}


