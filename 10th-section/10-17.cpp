#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Sales_data {
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
public:
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);

	// operations on Sales_data objects
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
	bool compareIsbn(const Sales_data& data1, const Sales_data& data2);

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

bool compareIsbn(const Sales_data& data1, const Sales_data& data2){
	return data1.isbn().size() < data2.isbn().size();
	//不知道这里的排序是否有更深层次的要求
}

void print(vector<Sales_data>&data){
	for (auto i : data)
		cout << i.isbn() << endl;
}

int main(){

	vector<Sales_data>data_container =
	{ { "the", 0, 0 },
	{ "red", 0, 0 },
	{ "fox", 0, 0 },
	{ "jumps", 0, 0 },
	{ "over", 0, 0 },
	{ "the", 0, 0 },
	{ "slow", 0, 0 },
	{ "red", 0, 0 },
	{ "title", 0, 0 }
	};
	stable_sort(
		data_container.begin(),
		data_container.end(), 
		[](const Sales_data& data1, const Sales_data& data2){
		return data1.isbn().size() < data2.isbn().size();}
	);

	print(data_container);
	return 0;
}
