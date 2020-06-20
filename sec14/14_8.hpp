#ifndef _14_8_HPP_
#define _14_8_HPP_

#include <iostream>
#include <string>
using namespace std;

class Employee{
    friend bool operator==(const Employee ployee_a, const Employee ployee_b);
    friend bool operator!=(const Employee ployee_a, const Employee ployee_b);
    friend ostream& operator<<(ostream& os_cout, const Employee& ployee_a);
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



#endif