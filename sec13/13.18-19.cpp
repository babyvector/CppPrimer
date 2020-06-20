//13.18
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee{
    public:
    Employee() =default;
    Employee(string s):name(s),id(id_start){
    }

    string name;
    int id;
    static int id_start;
};
int Employee::id_start = 0;

int main(){
    Employee ployee("xiaohua");
    cout<<ployee.name<<" "<<ployee.id<<endl;
    return 0;
}
/*
    13.19
    没有必要，在现实中员工没有拷贝的意义

    class Employee{
        public:
        Employee() =default;
        Employee(string s):name(s),id(id_start){
        Employee(const Employee&) = delete;
        Employee& operator=(const Employee&) = delete;
    }

    string name;
    int id;
    static int id_start;
}; 
*/