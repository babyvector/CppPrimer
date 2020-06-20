/*
    12.8出现的情况是：返回值类型不匹配
*/
//12.9解释下面代码
#include<iostream>
#include<string>
#include<memory>
#include<vector>


using namespace std;

int main(){
    int *q = new int(42), *r = new int(100);
    r = q;
    cout<<"the r value is:"<<*r<<endl;
    //r重新指向q,但是r指向的内存并没有被释放     
    auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
    r2 = q2;
    cout<<"the r2 value is:"<<*r2<<endl;
    cout<<"the q2 value is:"<<*q2<<endl;
    //r2重新指向q2，但是r2所指向的内存已经被释放了
    return 0;
}

