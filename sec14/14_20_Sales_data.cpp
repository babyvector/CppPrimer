#include "14_20_Sales_data.hpp"

using namespace std;

Sales_data operator+(const Sales_data& a, const Sales_data& b){

    return Sales_data(a.bookNo, a.units_sold + b.units_sold, a.revenue/a.units_sold);

}

ostream& operator<<(ostream& os_cout, const Sales_data &item){
        os_cout<<item.bookNo<<" "<<item.units_sold<<" "<<item.revenue<<std::endl;
        return os_cout;
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

Sales_data Sales_data::add(const Sales_data& book_a, const Sales_data& book_b){
    Sales_data * book_new = new Sales_data(book_a.bookNo, book_a.units_sold + book_b.units_sold, book_a.revenue);
    return *book_new;
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

