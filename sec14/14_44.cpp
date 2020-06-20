#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

double add(double a, double b)
{
    return a+b;
}

class divide{

public:
    double operator()(double a, double b){
        return a/b;
    }
};

auto mod = [](double a, double b){return (int)a%(int)b;};

int main(){

    map<string, function<double(double, double)> >binops = 
        {
            {"+", add},                                 //函数指针
            {"-", std::minus<double>()},                //标准函数库对象
            {"*", [](double a, double b){return a*b;}}, //未命名的lambda
            {"/", divide()},                            //用户定义的函数对象
            {"%", mod}                                  //命名了的lambda对象
            /*注意在  -  和   /  他们二者其实是没有大区别的不过一个是模板类而且是在标准库中定义的*/
        };

    double rhs, lhs;
    string caculator;
    cin>>rhs>>caculator>>lhs;

    cout<<"final caculate result is:"<<binops[caculator](rhs, lhs)<<endl;

    return 0;
}
