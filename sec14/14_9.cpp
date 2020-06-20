#include "14_9.hpp"

ostream& operator<<(ostream& os_cout, const Sales_data &item){
        os_cout<<"the bookNo: "<<item.bookNo<<" "<<"the units_sold: "<<item.units_sold<<" "<<"the revenue:"<<item.revenue<<std::endl;
        return os_cout;
}

istream& operator>>(istream& os_in, Sales_data &item){
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

std::string Sales_data::isbn(){
    return bookNo;
}

Sales_data& Sales_data::combine(const Sales_data & book_input){
    if(this->isbn() == book_input.bookNo){
        units_sold += book_input.units_sold;
        
    }
    return *this;
}

Sales_data Sales_data::add(const Sales_data& book_a, const Sales_data& book_b) const{
    return Sales_data(book_a.bookNo, book_a.units_sold + book_b.units_sold, book_a.revenue);
}
Sales_data& Sales_data::read(std::istream & os_cin){
   
    os_cin>>bookNo;
    os_cin>>units_sold;
    os_cin>>revenue;
    return *this;
}
Sales_data& Sales_data::print(std::ostream& os_cout){

    os_cout<<bookNo<<" "<<units_sold<<" "<<revenue<<std::endl;
    return *this;
}
