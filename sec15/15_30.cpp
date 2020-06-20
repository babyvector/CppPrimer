#include "15_15_Quote.hpp"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Basket{
public:

    void add_item(const Quote &sale)
        {items.insert(shared_ptr<Quote>(sale.clone()));}
    void add_item(Quote&& sale)
    {
        items.insert(shared_ptr<Quote>(std::move(sale).clone()));
    }
    double total_receipt(ostream&) const;

private:
    static bool compare(const shared_ptr<Quote> &lhs,
                        const shared_ptr<Quote> &rhs)
                        {return lhs->isbn() < rhs->isbn();}  
    
    multiset<shared_ptr<Quote>, decltype(compare)*>items{compare};
};

double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;
    for(auto iter = items.cbegin();
             iter != items.cend();
             iter = items.upper_bound(*iter)){
                 //upper_bound返回一个迭代器，该迭代器指向这批元素的尾后位置
                 sum += print_total(os, **iter, items.count(*iter));
             }
    os<<"Total Sales: "<<sum<<endl;
    return sum;
}


int main(){

    vector<Quote> qvec;
    qvec.push_back(Quote("dadada",25));
    qvec.push_back(Bulk_quote("xiaowangzi", 12, 15, 0.2));
    qvec.push_back(Bulk_quote("datouerzi", 12, 15, 0.2));
    qvec.push_back(Bulk_quote("xiaotoubaba", 12, 15, 0.2));

    cout<<qvec[0].net_price(20)<<endl;
    cout<<qvec[1].net_price(10)<<endl;

    vector<shared_ptr<Quote>> pqvec;
    pqvec.push_back(make_shared<Bulk_quote>(Bulk_quote("xiaowangzi", 12, 15, 0.2)));
    pqvec.push_back(make_shared<Bulk_quote>(Bulk_quote("xiaowangzi", 12, 15, 0.2)));
    pqvec.push_back(make_shared<Bulk_quote>(Bulk_quote("xiaowangzi", 12, 15, 0.2)));
    
    cout<<pqvec[0]->net_price(20)<<endl;
    cout<<pqvec[1]->net_price(10)<<endl;

    cout<<"Start test basket:"<<endl;
    Basket basket1;
    for(auto item:qvec)
        basket1.add_item(item);
    basket1.total_receipt(cout);



    return 0;
}