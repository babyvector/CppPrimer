#ifndef _12_19_STRBLOBPTR_HPP_
#define _12_19_STRBLOBPTR_HPP_

#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;
class StrBlobPtr;
class StrBlob{
	friend class StrBlobPtr;
    public:
		typedef std::vector<std::string>::size_type size_type;
		StrBlob();
		StrBlob(std::initializer_list<std::string> il);
		size_type size() const {return data->size();}
		bool empty() const {return data->empty();}
		int size();
		//添加和删除元素
		void push_back(const std::string &t)const{data->push_back(t);}
		void pop_back();
		std::string & front();
		std::string & back();
		std::string & front()const;
		int use_count() { return data.use_count(); }
		StrBlobPtr begin();
		StrBlobPtr end();
	private:
		int test_value;
		std::shared_ptr<std::vector<std::string>> data;
		//如果data[i]不合法，抛出一个异常
		void check(size_type i,const std::string &msg)const; 
};

class StrBlobPtr{
	
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob&a, size_t sz = 0):
        wptr(a.data),curr(sz){}
    string& deref()const;
    StrBlobPtr& incr();     //前缀递增
private:
    //若检查成功，check返回一个指向vector的shared_ptr
    shared_ptr<vector<string>>  check(size_t, const string&) const;
    //保存一个weak_ptr<std::vector<string>>wptr;
	weak_ptr<vector<string>> wptr;//在数组中的当前位置
    size_t curr;

};

#endif