#include "15_15_Quote.hpp"

int main(){
    Bulk_quote bulk("xiaowangzi", 9.99, 10, 0.05);
    Disc_Quote disc;
    print_total(cout, bulk, 15);

    return 0;
}