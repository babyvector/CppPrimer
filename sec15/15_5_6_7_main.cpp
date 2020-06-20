#include "15_5_6_7.hpp"

int main(){
    
    Quote basic("xiaowangzi", 9.99);
    Bulk_quote bulk("xiaowangzi", 9.99, 10, 0.05);
    print_total(cout, basic, 15);
    print_total(cout, bulk, 15);

    return 0;
}