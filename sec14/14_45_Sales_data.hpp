#ifndef SALES_DATE_H
#define SALES_DATE_H
#include <string>
#include <iostream>

using namespace std;

class Sales_data{
    //new versioin
    friend ostream& operator<<(ostream& os_cout, const Sales_data &item);
    friend Sales_data operator+(const Sales_data& a, const Sales_data& b);
    friend istream& operator>>(istream& os_in, Sales_data &item);
    //old version
    friend Sales_data add(const Sales_data& book_a, const Sales_data& book_b);
    friend istream& read(std::istream& os_cin, Sales_data&);
    friend ostream& print(std::ostream& os_cout, const Sales_data&);
public:
    Sales_data() = default;
    Sales_data(const std::string &input_bookNo, const unsigned input_units_sold, const double price):
               bookNo(input_bookNo),units_sold(input_units_sold),revenue(input_units_sold * price){}
    Sales_data(const Sales_data& rhs):bookNo(rhs.bookNo),units_sold(rhs.units_sold),revenue(rhs.revenue){}
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator=(const Sales_data&);
    Sales_data& operator=(const string&);

    operator string() const;
    operator double() const;

    std::string isbn();
    Sales_data& combine(const Sales_data& book_input);
    
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};

#endif