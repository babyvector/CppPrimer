#include "15_15_Quote.hpp"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main(){

    vector<Quote> qvec;
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
    /*
        15.29看看最终执行的结果是否一致：
        最终执行的结果不一致，因为net_price是虚函数，在最后执行函数的时候发生了动态绑定。
     */

    return 0;
}
