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
        StrBlob(const StrBlob & obj){
            cout<<"copy..."<<endl;
            test_value = obj.test_value;
            data = make_shared<vector<string>>();
            data->assign(obj.data->begin(),obj.data->end());
        
        }
        StrBlob& operator=(const StrBlob &obj){
            cout<<"=..."<<endl;
            test_value = obj.test_value;
            data = make_shared<vector<string>>();
            data->assign(obj.data->begin(),obj.data->end());
            return *this;
        }
		size_type size() const {return data->size();}
		bool empty() const {return data->empty();}

		void push_back(const std::string &t)const{data->push_back(t);}
		void pop_back();
		std::string & front();
		std::string & back();
		int size();
		std::string & front()const;
	//private:
		int test_value;
		std::shared_ptr<std::vector<std::string>> data;
		void check(size_type i,const std::string &msg)const; 
};
StrBlob::StrBlob(): data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string>il):
		 data(make_shared<vector<string>>(il)){
             cout<<"creating..."<<endl;
         }
void StrBlob::check(size_type i, const string &msg) const
{
	if(i >= data->size())
		throw out_of_range(msg);
}
string & StrBlob::front()
{
	//
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
	
    StrBlob b2 = {"a", "an", "the"};
    StrBlob b3 = b2;
    for(auto item : *b2.data){
        cout<<item<<endl;
    }
    b2.data->erase(b2.data->begin());
    for(auto item : *b2.data){
        cout<<item<<endl;
    }
    for(auto item : *b3.data){
        cout<<item<<endl;
    }
	//cout<<"hello world."<<endl;
    
	return 0;
} 
