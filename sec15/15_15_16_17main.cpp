#include "15_15_Quote.hpp"

int main(){
    Bulk_quote bulk("xiaowangzi", 9.99, 10, 0.05);
    Disc_Quote disc;
    print_total(cout, bulk, 15);

    return 0;
}

/*
    15.16 改写533中的练习（15.7）练习中编写的数量受限的折扣策略，令其继承Disc_quote
            已经改写成功
    15.17 尝试定义一个Disc_quote的对象，看看编译器给出的错误信息是什么？
          cannot declare variable 'disc' to be of abstract type 'Disc_Quote'
          because the following virtual functions are pure within 'Disc_Quote':
 */