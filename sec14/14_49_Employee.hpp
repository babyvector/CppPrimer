#ifndef _14_49_EMPLOYEE_HPP_
#define _14_49_EMPLOYEE_HPP_

#include <iostream>
#include <string>
using namespace std;

class Employee{
    friend bool operator==(const Employee ployee_a, const Employee ployee_b);
    friend bool operator!=(const Employee ployee_a, const Employee ployee_b);
    friend ostream& operator<<(ostream& os_cout, const Employee& ployee_a);
    friend istream& operator>>(istream& os_in, Employee& ployee_a);
    friend Employee operator+(Employee& ployee_a, Employee& ployee_b);

    public:
        Employee(string in_name = "normal ployee.", string in_title = "", int in_age = 0, int in_id = 0,int in_year_cost = 0):
                name(in_name),title(in_title),age(in_age),id(in_id),year_cost(in_year_cost){}
        Employee(const Employee&);
        Employee& operator=(const Employee&);
        Employee& operator=(const Employee&&);
        Employee& operator+=(Employee&);
        operator bool();

        ~Employee();
    private:
        string name;
        string title;
        int age;
        int id;
        int year_cost;

};



#endif