#ifndef _14_17_HPP_
#define _14_17_HPP_

#include <iostream>
#include <string>
using namespace std;

/*
 * 可以含有相等运算符
 */
class Employee{
    friend bool operator==(const Employee ployee_a, const Employee ployee_b);
    friend bool operator!=(const Employee ployee_a, const Employee ployee_b);
    friend ostream& operator<<(ostream& os_cout, const Employee& ployee_a);
    friend istream& operator>>(istream& os_in, Employee& ployee_a);
    
    friend Employee operator+(Employee& ployee_a, Employee& ployee_b){
        auto tmp = ployee_a;
        return tmp+=ployee_b;
    }

    public:
        Employee(string s = "normal ployee."):title(s){cout<<"invoking the constructor."<<endl;}
        Employee(string in_name, string in_title, int in_age, int in_id,int in_year_cost):
                name(in_name),title(in_title),age(in_age),id(in_id),year_cost(in_year_cost){}

        //Employee& operator=(const Employee&){cout<<"test if create copy= function automatically."<<endl; return *this;}
        Employee& operator=(const Employee&s){
            cout<<"test if create copy= function automatically."<<endl; 
            name = s.name;
            title = s.title;
            age = s.age;
            id = s.id;
            year_cost = s.year_cost;
            return *this;
        }
        Employee& operator+=(Employee& ployee_a){
            this->year_cost += ployee_a.year_cost;
            return *this;
        };
    private:
        string name;
        string title;
        int age;
        int id;
        int year_cost;

};



#endif