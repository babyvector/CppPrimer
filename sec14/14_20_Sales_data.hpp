#ifndef SALES_DATE_H
#define SALES_DATE_H
#include <string>
#include <iostream>

using namespace std;

class Sales_data{
    friend ostream& operator<<(ostream& os_cout, const Sales_data &item);
    friend Sales_data operator+(const Sales_data& a, const Sales_data& b);
public:
    Sales_data() = default;
    Sales_data(const std::string &input_bookNo, const unsigned input_units_sold, const double price):
               bookNo(input_bookNo),units_sold(input_units_sold),revenue(input_units_sold * price){}
    Sales_data& operator+=(const Sales_data& b){
        
        units_sold += b.units_sold;
        revenue += b.revenue;
        return *this;
    }
    
    

    std::string isbn();
    Sales_data add(const Sales_data& book_a, const Sales_data& book_b);
    Sales_data& combine(const Sales_data& book_input); 
    Sales_data& read(std::istream& os_cin);
    Sales_data& print(std::ostream& os_cout);
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};

#endif