#include "15_3.hpp"
#include <iostream>

int main(){

    Quote basic("xiaowangzi", 10);
    Bulk_quote bulk("xiaowangzi", 10);

    print_total(cout, basic, 20);
    print_total(cout, bulk, 20);
    return 0;
}
