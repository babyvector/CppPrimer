/*
    7.40选择Employee

*/

#include <iostream>
#include <string>
using namespace std;

class Employee{
    friend bool operator==(const Employee ployee_a, const Employee ployee_b);
    friend bool operator!=(const Employee ployee_a, const Employee ployee_b);
    public:
        Employee(string s = "normal ployee."):title(s){}
        Employee(string in_name, string in_title, int in_age, int in_id):
                name(in_name),title(in_title),age(in_age),id(in_id){}
    private:
        string name;
        string title;
        int age;
        int id;

};
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
    return 0;
}