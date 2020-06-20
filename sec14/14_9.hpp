#ifndef _14_9_HPP_
#define _14_9_HPP_
#include <string>
#include <iostream>

using namespace std;

class Sales_data{
    friend ostream& operator<<(ostream& os_cout, const Sales_data &item);
    friend istream& operator>>(istream& os_in, Sales_data &item);
public:
    Sales_data() = default;
    Sales_data(const std::string &input_bookNo, const unsigned input_units_sold, const double input_revenue):
               bookNo(input_bookNo),units_sold(input_units_sold),revenue(input_revenue){}

    Sales_data(const Sales_data& s){
        bookNo = s.bookNo;
        units_sold = s.units_sold;
        revenue = s.revenue;
        cout<<"invoking the copy constructor"<<endl;
    };
    Sales_data& operator=(const Sales_data& s){
        bookNo = s.bookNo;
        units_sold = s.units_sold;
        revenue = s.revenue;
        cout<<"invoking the copy= constructor"<<endl;
        return *this;
    };

    std::string isbn();
    Sales_data& combine(const Sales_data& book_input); 
    Sales_data& read(std::istream& os_cin);
    Sales_data& print(std::ostream& os_cout);
    Sales_data add(const Sales_data& book_a, const Sales_data& book_b) const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};
#endif