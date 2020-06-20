/*
    7.40选择Employee

*/
#include "14_12.hpp"

istream& operator>>(istream& os_in, Employee& ployee_a){
    os_in>>ployee_a.name;
    os_in>>ployee_a.title;
    os_in>>ployee_a.age;
    os_in>>ployee_a.id;

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
        <<"id:"<<ployee_a.id;
    return os_cout;
}

bool operator==(const Employee ployee_a, const Employee ployee_b){

    return ployee_a.name == ployee_b.name &&
           ployee_a.title == ployee_b.title &&
           ployee_a.age == ployee_b.age &&
           ployee_a.id ==  ployee_b.id;


}

bool operator!=(const Employee ployee_a, const Employee ployee_b){
    return !(ployee_a == ployee_b);
}

int main(){
    //可以对一个两个对象是否相等进行重载
    Employee a,b;
    cout<<(a == b)<<endl;
    cout<<("name" != "name")<<endl;
    auto s1 = "test1";
    auto s2 = "test1";
    cout<<int(s1)<<endl;
    cout<<int(s2)<<endl;
    Employee c("xiaohong","CEO", 35, 10);
    cout<<c<<endl;
    Employee d;
    cin>>d;
    return 0;
}