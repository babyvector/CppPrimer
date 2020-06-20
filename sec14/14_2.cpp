#include <iostream>
#include "Sales_data.h"
ostream& operator<<(ostream& os_cout, const Sales_data &item);
using namespace std;
int main(){
    Sales_data book1;
    Sales_data book2("fairy tale", 1, 10.0);
    Sales_data book3("fairy tale", 3, 10.0);
    Sales_data book4("idioms", 3, 69.0);
    Sales_data book5("idioms", 3, 69.0);
    Sales_data book6;

    std::cout<<"here is book1"<<std::endl;
    std::cout<<book1.isbn()<<std::endl;
    
    std::cout<<"here is book2 combine book3"<<std::endl;
    book2.combine(book3);

    std::cout<<"here is add book4 and book5"<<std::endl;
    std::cout<<add(book4, book5).isbn()<<std::endl;
    
    //book6.read(std::cin);
    //book6.print(std::cout);

    //std::cout<<book4<<std::endl;
    cout<<book4;
    return 0;
}