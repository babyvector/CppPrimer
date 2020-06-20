#ifndef _15_5_6_7_QUOTE_H_
#define _15_5_6_7_QUOTE_H_

#include <iostream>
#include <string>

using namespace std;

class Quote{
public:
    Quote() = default;
    Quote(const string &book, double sales_price):
        bookNo(book),price(sales_price){}
    string isbn() const {return bookNo;}
    //返回给定数量的书籍的销售总额
    //派生类负责改写并使用不同的折扣计算算法
    virtual double net_price(size_t n)const
        {return n*price;}
    virtual ~Quote() = default;    //对析构函数进行动态绑定
private:
    string bookNo;                 //书籍的ISBN编号

protected:
    double price = 0.0;            //代表普通状态下不打折的价格

};

class Bulk_quote:public Quote{     //Bulk_quote继承了Quote,但是可以访问其内部的protected成员
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p, size_t qty, double disc):
        Quote(book, p), min_qty(qty), discount(disc){}
    double net_price(size_t) const override;

private:
    size_t min_qty = 0;            //适用折扣政策的最低购买量
    double discount = 0.0;         //以小数表示折扣额
};


double print_total(ostream &os,
                   const Quote &item, size_t n);
#endif