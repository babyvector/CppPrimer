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
		//��Ӻ�ɾ��Ԫ��
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
		//���data[i]���Ϸ����׳�һ���쳣
		void check(size_type i,const std::string &msg)const; 
};
//�������캯����ʹ�ó�ʼ���б�����ʼ����data��Ա������ָ��һ����̬�����vector
//Ĭ�Ϲ��캯������һ����vector������һ��initializer_list�Ĺ��캯�������������
//����Ӧ��vector���캯�����˹��캯��ͨ�������б��е�ֵ����ʼ��vector��Ԫ�� 
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
	//���vectorΪ�գ�check���׳�һ���쳣
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
		/*��������ÿ��Կ�����ʱb1�е�vector<string>ָ���Ѿ����ͷ���*/
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
	//���յĽ������4 
	cout<<"hello world."<<endl;
	return 0;
} 

/*
	12.2
    ���Ա�д������const�汾��front��back 
	 
*/
/*
	12.3
	StrBlob��Ҫconst�汾��push_back��pop_back�������Ҫ��ӽ�ȥ���������Ϊʲô����Ҫ
	github�ϵĴ𰸣������Ը�⣬�㵱Ȼ�����������������ƺ�û���κκϺ��߼������ɡ�������
	û�б�Թ����Ϊ�ⲻ���޸����ݣ�����һ��ָ�룩�������޸�������ָ��Ķ���������ʹ��
	constָ��Ҫ��Ĺ�����ȫ�Ϸ������ߣ�David Schwartz��
	 
*/

/*
	12.4
	�����ǵ�check�����У�û�м��i�Ƿ����0.Ϊʲô���Ժ��������飿
	 github�ϵĴ𰸣���Ϊ�����ж���ı���i��һ���޷��ű������޷������в����ܴ���С��0������ 
*/

/*
	12.5
	����δ��д����һ��initializer_list explicit�����Ĺ��캯�������������Ʋ��Ե��е��ȱ�㡣
	github�ϵĴ𰸣�
		�ŵ㣺
			�������������Զ�ת����ʹ�ô˹��캯�������ǿ����������ʶ������ʹ�����ĸ��ࡣ
		ȱ�㣺
			��������ʹ�ù��캯��������һ����ʱ��StrBlob���󡣲���ʹ����ʾ���캯���ĳ�ʼ����
			������ʽ��������ʹ�á� 
	
*/ 
