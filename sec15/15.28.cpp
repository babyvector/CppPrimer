//以下的代码是15.28的题解，有一部分自己会写，还有一部分是抄的github上的

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;


class Quote{
public:
    Quote() = default;      //关于=default
    Quote(const string &book, double sales_price):
        bookNo(book),price(sales_price){}
    std::string isbn() const {return bookNo;}
    //返回给定数量的书籍的销售总额
    //派生类负责改写并使用不同的折扣计算算法
    virtual double net_price(size_t n)const{
        return n*price;
    }
    virtual ~Quote() = default;     //对析构函数进行动态绑定


    private:
        string bookNo;              //书籍的ISBN编号
    
    protected:
        double price = 0.0;         //代表普通状态下不打折

};

class Disc_quote:public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const string&book, double price,size_t qty,double disc):
        Quote(book, price),
        quantity(qty),discount(disc){}

    double net_price(std::size_t) const = 0;

protected:
    std::size_t quantity = 0;   //折扣适用的购买量
    double discount = 0.0;      //表示折扣的小数值
};
/*
    接下来可以重新实现Bulk_quote了，这一次我们让它继承Disc_quote而非
    直接继承Quote;
        当同一书籍的销售量超过某个值的时候启用折扣
        折扣的值是一个小于1的正的小数值，以此来降低正常销售价格
*/
/*
    这个版本的Bulk_quote的直接基类是Disc_quote，间接基类是Quote。每个
    Bulk_quote对象包含三个子对象：一个(空的)Bulk_quote部分、一个
    Disc_quote子对象和一个Quote子对象。
*/
class Bulk_quote:public Disc_quote{

public:
    Bulk_quote() = default;
    Bulk_quote(const string&book, double price, 
               size_t qty, double disc):
        Disc_quote(book,price,qty,disc){}
    //覆盖基类中的函数版本以实现一种新的折扣策略
    double net_price(size_t)const override;

};

int main(){



    return 0;
}