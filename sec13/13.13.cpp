/*
#include <iostream>
#include <vector>
#include <initializer_list>

struct X {
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }
    ~X() { std::cout << "~X()" << std::endl; }
};

void f(const X &rx, X x)
{
    std::vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx);
    vec.push_back(x);
}

int main()
{
    X *px = new X;
    f(*px, *px);
    delete px;

    return 0;
}
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct X{
    public:
        X(){cout<<"X()"<<endl;}
        X(const X&){cout<<"X(const X&)"<<endl;}
        X& operator=(const X& obj){
            cout<<"X& operator=(const X& obj)"<<endl;
            length = obj.length;
            name = obj.name;
            return *this;
        } 
        ~X(){
            cout<<"~X()"<<endl;        
        }
    private:
        int length;
        string name;
    };
void use_x(const X){
    cout<<"we are at use_x"<<endl;
}
void use_xr(const X&){
    cout<<"we are at use_xr"<<endl;
}
int main(){

    //作为非引用和引用传递
    /*
    X a;
    use_x(a);
    use_xr(a);
    */
    //动态分配它们
    /*
    X* b = new X();
    use_x(*b);
    use_xr(*b);  
    */
   //放入容器中
   X c,d,e,f,g;
   vector<X> X_vector;
   X_vector.reserve(5);//这个点不可少，不然就会出现改变容器大小之后再进行相应的操作
   cout<<"push c"<<endl;
   X_vector.push_back(c);
   cout<<"X_vector.size()"<<X_vector.size()<<endl;
   cout<<"push d"<<endl;
   X_vector.push_back(d);
   cout<<"X_vector.size()"<<X_vector.size()<<endl;
   cout<<"push e"<<endl;
   X_vector.push_back(e);
   cout<<"X_vector.size()"<<X_vector.size()<<endl;
   cout<<"push f"<<endl;
   X_vector.push_back(f);
   cout<<"X_vector.size()"<<X_vector.size()<<endl;
   cout<<"push g"<<endl;
   X_vector.push_back(g);
   cout<<"X_vector.size()"<<X_vector.size()<<endl;
   
   cout<<"next we get into {}"<<endl;
   {X_vector;}
   cout<<"we get out of X_vector"<<endl;
    return 0;
}