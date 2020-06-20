#ifndef _13_33_H_
#define _13_33_H_

#include <string>
#include <set>

using namespace std;

class Message;
class Folder{
    friend class Message;
public:
    explicit Folder(const string& input):dir_name(input){
        cout<<"we are invoking Folder constructer."<<endl;
    }
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();

    void addMsg(Message*);
    void remMsg(Message*);

    void print(){
        cout<<"the folder is"<<dir_name<<endl;
    }
private:
    string dir_name;
    set<Message*>messages;
    void add_to_Msgs(const Folder&);
    void remove_from_Msgs();
};

class Message{
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
public:
    //构造函数：folders被隐式初始化为空集合
    explicit Message(const string &str = ""):
        contents(str){
            cout<<"we are invoking message constructer."<<endl;
        }
    //拷贝构造函数：拷贝控制成员，用来管理指向本Message的指针
    Message(const Message&);                
    //拷贝赋值运算符
    Message& operator=(const Message&);  
    //移动构造函数
    Message(Message &&m):contents(std::move(m.contents));   
    //移动赋值运算符
    Message& operator=(Message &&rhs){
        if(this != &rhs){//直接检查自赋值情况
            remove_from_Folders();              //销毁左侧对象
            contents = std::move(rhs.contents); //移动赋值运算符
            move_Folders(&rhs);                 //重置Folders指向本Message
        }
        return *this;
    }
    //析构函数
    ~Message();                             
    //从给定Folder集合中添加/删除本Message
    void save(Folder&);
    void remove(Folder&);
    void move_Folders(Message *m);

    void print(){
        cout<<"the message is:"<<contents<<endl;
    }
    void print_folders(){
        for(auto f:folders){
            cout<<f->dir_name<<endl;
        }
    }
private:
    string contents;                        //实际消息文本
    set<Folder*>folders;                    //包含本Message的Folder
    //拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
    //将本Message添加到指向参数的Folder中
    void add_to_Folders(const Message&);
    //从folders中的每个Folder中删除本Message
    void remove_from_Folders();
};

#endif