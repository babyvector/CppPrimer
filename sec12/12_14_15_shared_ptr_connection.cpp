#include <iostream>
#include <memory>

using namespace std;

struct destination{};
struct connection{};

struct connection connect(destination* in_des){
    cout<<"we are going to connect."<<endl;
    struct connection rval;
    return rval;
}
void disconnect(struct connection*){
    cout<<"we are going to close connection."<<endl;
}

void f(struct destination &d/*其他参数*/){
    //获得一个连接，记住使用完后要关闭
    struct connection c = connect(&d);
    //shared_ptr<struct connection> p(&c, disconnect);
    shared_ptr<struct connection> p(&c, [](struct connection * to_del){disconnect(to_del);});
}

int main(){
    struct destination tmp_des;
    f(tmp_des);

}