#include "15_3.hpp"

double print_total(ostream &os,
                   const Quote &item, size_t n)
                   {
                       //根据传入item形参的对象类型调用Quote::net_price
                       //或者Bulk_quote::net_price
                       double ret = item.net_price(n);
                       os<<"ISBN:"<<item.isbn()             //调用Quote::isbn
                         <<" # sold: "<< n <<" total due: "<<ret<<endl;
                       return ret;
                   }

double Bulk_quote::net_price(size_t n)
const
{
    return n*price*0.9;
}