#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Quote{
    friend bool operator !=(const Quote& lhs, const Quote& rhs);
public:
    //默认构造函数
    Quote():bookNo(""),price(0){cout<<"using default constructor."<<endl;}
    //构造函数1
    Quote(string _string,float _price):bookNo(_string),price(_price){}
    //拷贝构造函数
    Quote(const Quote&rhs){
        price = rhs.price ;
        bookNo = rhs.bookNo;
    }
    //拷贝赋值函数
    Quote&operator=(Quote&rhs){
        //要考虑到自赋值的情况
        Quote tmp(rhs);
        //如何在销毁之后销毁自身
        price = tmp.price;
        bookNo = tmp.bookNo;

        return *this;

    }
    //移动构造函数
    Quote(Quote&& input)noexcept:bookNo(std::move(input.bookNo)),price(std::move(input.price)){
        //不会，抄袭的github上的
        cout<<"Quote: move constructing.\n";
    }
    //移动赋值函数
    Quote& operator = (const Quote&& rhs) noexcept{
        //不会，抄袭的github上的
        if(rhs.bookNo != this->bookNo && rhs.price != this->price){
            bookNo = std::move(rhs.bookNo);
            price = std::move(rhs.price);
        }
        return *this;
    }
    /*
        注意：凡是涉及到移动的操作，都是使用std::move()函数
              而没有使用到=或者拷贝操作，这样做就能避免所有的
              拷贝，从而实现某些无法拷贝的量的移动；或者避免
              拷贝而浪费性能。

        我们可以通过调用一个名为move的新标准库函数来获得绑定到
        左值上的右值的引用
    */
    string isbn() const{return bookNo;}
    virtual double net_price(size_t n)const{return n*price;}
    virtual void debug() const{
        cout<<"bookNo="<<this->bookNo<<" "
        <<"price="<<this->price<<endl;
    };
    
protected:
    float price;

private:
    string bookNo;
};
bool inline operator != (const Quote& lhs, const Quote& rhs){
    return lhs.bookNo != rhs.bookNo
           &&
           lhs.price != rhs.price;
}
class Disc_quote:public Quote{
    friend bool operator != (const Disc_quote &lhs, const Disc_quote &rhs);
public:
    Disc_quote(){
        cout<<" default constructing Disc_quote"<<endl;
    }
    //constructor
    Disc_quote(string _string, float _price, size_t _quantity, double _discount):
                Quote(_string, _price),quantity(_quantity),discount(_discount){

    }

    //copy constructor
    Disc_quote(Disc_quote & obj): Quote(obj),quantity(obj.quantity),discount(obj.discount){

    }
    //move constructor/*注意查看*/
    Disc_quote(Disc_quote&& move_obj):Quote(move_obj),quantity(move(move_obj.quantity)),discount(move(move_obj.discount)){

    }
    //copy =()
    Disc_quote&operator=(Disc_quote&input_obj){
        Quote::operator=(input_obj);/*注意这个函数的用法*/
        if(*this != input_obj){
            
            quantity = input_obj.quantity;
            discount = input_obj.discount;
            cout<<"Disc_quote:copy=()"<<endl;
        }
        return *this;
    }
    //move =()
    Disc_quote& operator=(Disc_quote &&rhs)noexcept{
        if(*this != rhs){
            Quote::operator=(std::move(rhs));
            this->quantity = std::move(rhs.quantity);
            this->discount = std::move(rhs.discount);
        }
        cout<<"Disc_quote:move=()"<<endl;
        return *this;

    }
    virtual double net_price(size_t n) const override = 0;

    virtual ~Disc_quote(){
        cout<<"destructing Dis_quote"<<endl;
    }
protected:
    size_t quantity = 3;
    double discount = 0.0;
};
/*在类的外面不可能有权限访问quantity和discount*/
bool inline operator!=(const Disc_quote &lhs, const Disc_quote&rhs){
    return Quote(lhs) != Quote(rhs)
/*  //当采用(Disc_quote &lhs, Disc_quote &rhs)不是使用const进行传递的时候
    //就会出现下面的错误
    15.28_from_github.cpp:125:23: error: no match for 'operator!=' (operand types are 'Quote' and 'Quote')
    125 |     return Quote(lhs) != Quote(rhs)
        |            ~~~~~~~~~~ ^~ ~~~~~~~~~~
        |            |             |
        |            Quote         Quote
    15.28_from_github.cpp:67:13: note: candidate: 'bool operator!=(Quote&, Quote&)' <near match>
    67 | bool inline operator != (Quote& lhs, Quote& rhs){
        |             ^~~~~~~~
    15.28_from_github.cpp:67:13: note:   conversion of argument 2 would be ill-formed:
    15.28_from_github.cpp:125:26: error: cannot bind non-const lvalue reference of type 'Quote&' to an rvalue of type 'Quote'
    125 |     return Quote(lhs) != Quote(rhs)
*/
            &&
            lhs.quantity != rhs.quantity
            &&
            lhs.discount != rhs.discount;
} 

class Bulk_quote:public Disc_quote{
public:
    Bulk_quote(){cout<<"default constructing Bulk_quote"<<endl;}
    /*
        下面的改变继承ex15.27的构造函数
        规则：
            1.只是直接继承base基类
            2.**默认，拷贝，移动构造函数不能被继承**
            3.任何自己的数字成员是被默认初始化的
            4.剩下的细节是在15.7.4章节
    */
   
   using Disc_quote::Disc_quote;
   /*
        //上面的代码相当于
        Bulk_quote(const std::string& b, double p, std::size_t q, double disc) :
        Disc_quote(b, p, q, disc) { std::cout << "Bulk_quote : constructor taking 4 parameters\n"; }

    */
   //copy constructor不能被继承所以要自己写出来
   Bulk_quote(Bulk_quote& bq):Disc_quote(bq){
       cout<<"Bulk_quote:move constructor."<<endl;
   }
   //copy = 仍然不能继承所以自己写
   Bulk_quote& operator=(Bulk_quote& rhs){
       Disc_quote::operator=(rhs);
       cout<<"Bulk_quote:copy=()"<<endl;
       return *this;
   }
   //move =
   Bulk_quote& operator=(Bulk_quote&& rhs){
       Disc_quote::operator=(move(rhs));
       cout<<"Bulk_quote:move=()"<<endl;
       return *this;
   }
   //move constructor
   Bulk_quote(Bulk_quote&&rhs):Disc_quote(move(rhs)){
       cout<<"Bulk_quote:move constructor"<<endl;
   }
   double net_price(size_t n)const override;
   void debug() const override;
   ~Bulk_quote() override{
       cout<<"destructing Bulk_quote"<<endl;
   }

};
double Bulk_quote::net_price(size_t n) const{
    return n*price *(n>=quantity ? 1-discount:1);
}
void Bulk_quote::debug() const{
    cout<<"min_qty="<<quantity<<" "
        <<"discount="<<this->discount<<" "<<endl;
}

/*
   注意这两种函数对Disc_quote()的构造
    //move =
   Bulk_quote& operator=(Bulk_quote&& rhs){
       Disc_quote::operator=(move(rhs));
       cout<<"Bulk_quote:move=()"<<endl;
       return *this;
   }
   //move constructor
   Bulk_quote(Bulk_quote&&rhs):Disc_quote(rhs){
       
   }

*/

int main(){
    /*
        采用对象存储和采用指针存储会出现两种不同的计算结果的原因：
            第一个结果：由于第一个向量中存储的是对象，因此没有多态性
                       在调用虚拟函数net_price时发生。本质上，对象
                       其中包含的是被推回的Bulk_quote对象的基类
                       Quote,因此，调用的虚拟net_price函数是Quote::
                       net_price。结果是没有折扣
            第二个结果：第二个向量中持有的是Quote对象的智能指针，
                       在这种情况下，多态性按预期发生。实际上虚函数
                       调用的是Bulk_quote::net_price因此产生折扣
    */
    vector<Quote> v;
    for(unsigned i = 1; i!= 10; ++i){
        v.push_back(Bulk_quote("sss", i*10.1, 10, 0.3));
    }
    double total = 0;
    for(const auto& b:v){
        total += b.net_price(20);
    }
    cout<<total<<endl;
    cout<<"================================"<<endl;
    vector<shared_ptr<Quote>>pv;
    for(unsigned i = 1; i != 10; ++i)
        pv.push_back(make_shared<Bulk_quote>(Bulk_quote("sss", i*10.1, 10, 0.3)));
    
    double total_p = 0;
    for(auto p:pv){
        total_p += p->net_price(20);
    }
    cout<<total_p<<endl;
    cout<<"以下测试右值引用的情况："<<endl;
    int i = 0, j=1;
    int &&k = move(j);
    cout<<k<<endl;
    j = 2;
    cout<<k<<" "<<j<<endl;
    return 0;
}