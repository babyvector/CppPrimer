#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <string.h>

using namespace std;

int main(){

    const char *a = "abc";
    const char *b = "def";
    char * union_char = new char[strlen(a) + strlen(b) + 1];
    int i = 0;
    while(a[i] != '\0'){
        union_char[i] = a[i];
        i++;
    }
    int j = 0;
    while(b[j] != '\0'){
        union_char[i] = b[j];
        i++;
        j++;
    }
    union_char[i] = '\0';
    cout<<"the union char is:"<<union_char<<endl;
    delete [] union_char;

    //连接两个标准库string对象
    string str_a = "ABC";
    string str_b = "DEF";
    string str_union;
    str_union = str_a + str_b;
    cout<<"the union string is:"<<str_union<<endl;
    return 0;
}