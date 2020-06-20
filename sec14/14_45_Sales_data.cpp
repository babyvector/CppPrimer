#include "14_45_Sales_data.hpp"

using namespace std;

Sales_data operator+(const Sales_data& a, const Sales_data& b)
{
    Sales_data tmp(a);
    return tmp+=b;
}

ostream& operator<<(ostream& os_cout, const Sales_data &item)
{
        os_cout<<item.bookNo<<" "<<item.units_sold<<" "<<item.revenue;
        return os_cout;
}

istream& operator>>(istream& os_in, Sales_data &item)
{
    double price;
    os_in>>item.bookNo>>item.units_sold>>price;
    cout<<"the os_in value is:"<<bool(os_in)<<endl;
    if(os_in)
        item.revenue = item.units_sold * price;
    else
    {
            item = Sales_data();
    }
    return os_in;
}

Sales_data& Sales_data::operator+=(const Sales_data& b)
{     
    units_sold += b.units_sold;
    revenue += b.revenue;
    return *this;
}

Sales_data& Sales_data::operator=(const Sales_data& s)
{
    bookNo = s.bookNo;
    units_sold = s.units_sold;
    revenue = s.revenue;
    cout<<"invoking the copy= constructor"<<endl;
    return *this;
};

Sales_data& Sales_data::operator=(const string& rhs)
{
    bookNo = rhs;
    return *this;
}

Sales_data::operator string() 
const
{
    return bookNo;
}

Sales_data::operator double() 
const
{
    return revenue;
}

std::string Sales_data::isbn()
{
    return bookNo;
}

Sales_data& Sales_data::combine(const Sales_data & book_input)
{
    if(this->isbn() == book_input.bookNo){

        units_sold += book_input.units_sold;
    }
    return *this;
}

Sales_data add(const Sales_data& book_a, const Sales_data& book_b)
{
    Sales_data * book_new = new Sales_data(book_a.bookNo, book_a.units_sold + book_b.units_sold, book_a.revenue);
    return *book_new;
}

istream& read(std::istream & os_cin, Sales_data& item)
{
    os_cin>>item.bookNo;
    os_cin>>item.units_sold;
    os_cin>>item.revenue;
    return os_cin;
}

ostream& print(std::ostream& os_cout, const Sales_data& item)
{
    os_cout<<item.bookNo<<" "<<item.units_sold<<" "<<item.revenue;
    return os_cout;
}

