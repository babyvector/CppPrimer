#ifndef _15_15_QUOTE_H_
#define _15_15_QUOTE_H_

#include <iostream>
#include <string>
#include <set>

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
    virtual void debug() const;
    virtual Quote* clone() const & {return new Quote(*this);}
    virtual Quote* clone() const && {return new Quote(std::move(*this));}
    virtual ~Quote() = default;    //对析构函数进行动态绑定
private:
    string bookNo;                 //书籍的ISBN编号

protected:
    double price = 0.0;            //代表普通状态下不打折的价格

};

class Disc_Quote:public Quote{
public:
    Disc_Quote() = default;
    Disc_Quote(const string &book, double sales_price, int quant, double disc):
        Quote(book, sales_price), quantity(quant), discount(disc){};
    double net_price(size_t n)const = 0;
protected:
    int quantity = 0;
    double discount = 0;
};

class Bulk_quote:public Disc_Quote{     //Bulk_quote继承了Quote,但是可以访问其内部的protected成员
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p, size_t qty, double disc):
        Disc_Quote(book, p, qty, disc){}
    double net_price(size_t) const override;//这个函数到底重载的是Disc_Quote还是Bulk_quote中的函数
    void debug() const override;
    Bulk_quote* clone() const & {return new Bulk_quote(*this);}
    Bulk_quote* clone() const && {return new Bulk_quote(std::move(*this));}

};

//下面这个类只是为了测试，已经经过override修饰过的派生类中的函数，在再派生的类中是否还能重载
class XBulk_quote:public Bulk_quote{
public:
    void debug() const;
};

double print_total(ostream &os,
                   const Quote &item, size_t n);
#endif