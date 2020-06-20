#ifndef _14_12_HPP_
#define _14_12_HPP_

#include <iostream>
#include <string>
using namespace std;

class Employee{
    friend bool operator==(const Employee ployee_a, const Employee ployee_b);
    friend bool operator!=(const Employee ployee_a, const Employee ployee_b);
    friend ostream& operator<<(ostream& os_cout, const Employee& ployee_a);
    friend istream& operator>>(istream& os_in, Employee& ployee_a);
    
    public:
        Employee(string s = "normal ployee."):title(s){cout<<"invoking the constructor."<<endl;}
        Employee(string in_name, string in_title, int in_age, int in_id):
                name(in_name),title(in_title),age(in_age),id(in_id){}

        //Employee& operator=(const Employee&){cout<<"test if create copy= function automatically."<<endl; return *this;}
        Employee& operator=(const Employee&s){
            cout<<"test if create copy= function automatically."<<endl; 
            name = s.name;
            title = s.title;
            age = s.age;
            id = s.id;
            return *this;
        }
    private:
        string name;
        string title;
        int age;
        int id;

};



#endif