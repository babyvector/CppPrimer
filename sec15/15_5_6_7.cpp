#include "15_5_6_7.hpp"

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

/*
double Bulk_quote::net_price(size_t cnt)
const
{
    if(cnt >= min_qty)
      return cnt * (1-discount) * price;
    else
    {
        return cnt * price;
    }
}
*/
/*15.7问题的答案，当购买书籍的数量不超过一个给定的限量时享受折扣，
      如果购买量一旦超过了限量，则超出部分将以原价销售。*/
double Bulk_quote::net_price(size_t cnt)
const
{
    if(cnt >= min_qty)
      return min_qty * (1-discount) * price + (cnt - min_qty) * price;
    else
    {
        return cnt * (1-discount) * price;
    }
}
