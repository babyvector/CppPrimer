#ifndef _14_27_CONSTSTRBLOBPTR_HPP_
#define _14_27_CONSTSTRBLOBPTR_HPP_

#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob{
	friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	friend bool operator<(const StrBlob&, const StrBlob&);
    public:
		typedef std::vector<std::string>::size_type size_type;
		StrBlob();
		StrBlob(StrBlob*s):test_value(move(s->test_value)),data(move(s->data)){
			cout<<"now we init use StrBlob(StrBlob*s)"<<endl;
		}
		StrBlob(std::initializer_list<std::string> il);

		const string& operator[](size_t index) const;//如果这里没有const就没法编译成功
		string& operator[](size_t index);
		
		size_type size() const {return data->size();}
		bool empty() const {return data->empty();}
		//添加和删除元素
		void push_back(const std::string &t)const{data->push_back(t);}
		void pop_back();
		std::string & front();
		std::string & back();
		std::string & front()const;
		int use_count() { return data.use_count(); }
		StrBlobPtr begin()const;
		StrBlobPtr end()const;
        ConstStrBlobPtr cbegin() const;//这里加上一个const有什么具体的作用??
        ConstStrBlobPtr cend() const;//这里加上const有什么具体的作用??
	private:
		int test_value;
		std::shared_ptr<std::vector<std::string>> data;
		//如果data[i]不合法，抛出一个异常
		void check(size_type i,const std::string &msg)const; 
};

class StrBlobPtr{
	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
	friend string* operator+(StrBlobPtr, const size_t int);
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(const StrBlob&a, size_t sz = 0):
        wptr(a.data),curr(sz){}

	const string& operator[](size_t index) const;//如果这里没有const就没法编译成功
	string& operator[](size_t index);
	StrBlobPtr& operator++();
	StrBlobPtr operator++(int);
	StrBlobPtr& operator--();
	StrBlobPtr operator--(int);
	

    string& deref();
    StrBlobPtr& incr();     //前缀递增
private:
    //若检查成功，check返回一个指向vector的shared_ptr
    shared_ptr<vector<string>>  check(size_t, const string&) const;
    //保存一个weak_ptr<std::vector<string>>wptr;
	weak_ptr<vector<string>> wptr;//在数组中的当前位置
    size_t curr;

};

class ConstStrBlobPtr{
public:
    ConstStrBlobPtr():curr(0){}
    ConstStrBlobPtr(const StrBlob&a, size_t sz = 0):
        wptr(a.data),curr(sz){}
    const string& deref()const;
    ConstStrBlobPtr& incr();     //前缀递增
private:
    //若检查成功，check返回一个指向vector的shared_ptr
    //这是一个只读接口！！（也就是不允许更改在函数内更改this这个隐藏的参数）
    shared_ptr<vector<string>>  check(size_t, const string&) const;
    //保存一个weak_ptr<std::vector<string>>wptr;
	weak_ptr<vector<string>> wptr;//在数组中的当前位置
    size_t curr;
};

#endif