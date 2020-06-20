//下一段代码测试了是否能将基类和派生类放置到同一个vector
#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Quote{
public:
    Quote():id_i(""),price(0),num(0){}
    Quote(string input_id,
          float input_price,
          int input_num):
          id_i(input_id),price(input_price),num(input_num){
              cout<<"id:"<<input_id<<" price:"<<input_price<<" num:"<<input_num<<endl;
          }
    virtual float net_price(){
        return num*price;
    };
private:
    string id_i;
    float price;
    int num;
};
class Bulk_quote:public Quote{
public:
    Bulk_quote(string input_id,
               float input_price,
               int input_num,
               float input_charge):Quote(input_id,input_price,input_num),
                                   charge(input_charge){
                                       cout<<"id:"<<input_id<<" price:"<<input_price
                                            <<" num:"<<input_num<<" charge:"<<input_charge<<endl;
          
                                   }
    float net_price(){
        cout<<"we invoke the net_price of Bulk_quote."<<endl;
        return (Quote::net_price() - charge);
    }
    void simple_print(){
        cout<<"the name is:"<<endl;
    }
private:
    float charge;
};
int main(){
    vector<shared_ptr<Quote> >basket;
    basket.push_back(
        make_shared<Quote>("0-201-82470-1",50,10)
    );
    basket.push_back(
        make_shared<Bulk_quote>("0-201-54848-8",50,10,.25)
    );
    cout<<basket[0]->net_price()<<endl;
    cout<<basket[1]->net_price()<<endl;
    //Bulk_quote out = *
    cout<<"hello world."<<endl;
    return 0;
}
