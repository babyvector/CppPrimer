/*
    7.40选择Employee

*/
#include "14_24.hpp"


bool operator==(const Employee ployee_a, const Employee ployee_b){

    return ployee_a.name == ployee_b.name &&
           ployee_a.title == ployee_b.title &&
           ployee_a.age == ployee_b.age &&
           ployee_a.id ==  ployee_b.id;
}

bool operator!=(const Employee ployee_a, const Employee ployee_b){

    return !(ployee_a == ployee_b);
}

istream& operator>>(istream& os_in, Employee& ployee_a){

    os_in>>ployee_a.name;
    os_in>>ployee_a.title;
    os_in>>ployee_a.age;
    os_in>>ployee_a.id;
    os_in>>ployee_a.year_cost;

    if(os_in)
        cout<<"the cin state is right."<<endl;
    else{
        cout<<"the cin state is error."<<endl;
        ployee_a = Employee();
        cout<<"reinit the ployee_a,ployee_a.title:"<<ployee_a.title<<endl;
    }
    
    return os_in;
}

ostream& operator<<(ostream& os_cout, const Employee& ployee_a){

    os_cout<<"name:"<<ployee_a.name
           <<"title:"<<ployee_a.title
           <<"age:"<<ployee_a.age
           <<"id:"<<ployee_a.id
           <<"year_cost"<<ployee_a.year_cost;
    return os_cout;
}

Employee operator+(Employee& ployee_a, Employee& ployee_b){

    auto tmp = ployee_a;
    return tmp+=ployee_b;
}

Employee::Employee(const Employee&rhs){

    name = rhs.name;
    title = rhs.title;
    age = rhs.age;
    id = rhs.id;
    year_cost = rhs.year_cost;
}

Employee& Employee::operator=(const Employee&&rhs){
    
    name = rhs.name;
    title = rhs.title;
    age = rhs.age;
    id = rhs.id;
    year_cost = rhs.year_cost;
    return *this;
}

Employee& Employee::operator=(const Employee&s){

    cout<<"test if create copy= function automatically."<<endl; 
    name = s.name;
    title = s.title;
    age = s.age;
    id = s.id;
    year_cost = s.year_cost;
    return *this;
}

Employee& Employee::operator+=(Employee& ployee_a){

    this->year_cost += ployee_a.year_cost;
    return *this;
}

Employee::~Employee(){
    cout<<"invoking ~Employee() function."<<endl;
}

int main(){
    
    /*以下是测试 拷贝赋值函数， 移动赋值运算符*/
    Employee e("xiaohong","CEO", 35, 10, 25);
    Employee f("xiaohua","CEO", 35, 10, 25);
    
    e = f;
    cout<<"after copy = :"<<endl;
    cout<<"e: "<<e<<endl;
    cout<<"f: "<<f<<endl;

    Employee g("xiaohong","CEO", 35, 10, 25);
    Employee h("xiaohua","CEO", 35, 10, 25);
    
    cout<<"test ~Employee() function start."<<endl;
    g = move(h);
    cout<<"test ~Employee() function end."<<endl;
    cout<<"after move = :"<<endl;
    cout<<"g: "<<g<<endl;
    cout<<"h: "<<h<<endl;
    
    /*
        14.25的解答说明：这个类不应该定义> < 等运算符，
        因为没有唯一可靠的逻辑 大于号， 小于号定义；
        而且这两个符号产生的意义与==号的意义也并不相同
    */
    

    return 0;
}