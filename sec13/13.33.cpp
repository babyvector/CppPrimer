#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "13.33.h"

using namespace std;
/*

    message->电子邮件
    folder ->消息目录
    注意：
    1. 为了记录message位于哪些folder中，每个message都会保存一个它所在folder
    的指针的set，同样的，每个folder都保存一个它包含的message的指针的set
    2. 观察这些操作，我们可以看到，析构函数和拷贝赋值运算符都必须从包含一条message
    的所有folder中删除它。类似的，拷贝构造函数和拷贝赋值运算符都要将一个message
    添加到给定的一组folder中。我们将定义两个private的工具函数来完成这些工作。
    3.拷贝赋值运算符通常执行拷贝构造函数和析构函数中也要做的工作。这种情况下，公共
    的工作应该放在private的工具函数中完成。

*/

/*注意：好好写拷贝构造函数和赋值拷贝函数，这两个函数很重要*/
/******************************** Folder *******************************/
Folder::Folder(const Folder&folder_c){
    messages = folder_c.messages;
    for(auto msg:messages){
        msg->save(*this);
    }
}

Folder& Folder::operator=(const Folder&folder_c){
    
    messages = folder_c.messages;
    //???????这样能防止自赋值发生意外的情况吗？
    return *this;
}

Folder::~Folder(){
    cout<<"we are invoking ~Folder()"<<endl;
}

void Folder::add_to_Msgs(const Folder &f){
    for(auto m: f.messages){
        m->folders.insert(this);
    }
}

void Folder::remove_from_Msgs(){
    for(auto m:messages)
        m->folders.erase(this);
}

void Folder::addMsg(Message* message){
    this->messages.insert(message);   
}

void Folder::remMsg(Message* message){
    /*
    auto item = this->messages.find(message);
    if( item != messages.end() ){
        this->messages.erase(item);
    };
    */
   //以上代码是自己写的，不够简洁，没掌握好erase用法
   messages.erase(message);
}


/******************************** Message *******************************/
inline
void swap(Message &lhs, Message &rhs){
    using std::swap;                        //在本例中严格来说并不需要，
                                            //但这是一个好习惯
    //将每个消息的指针从它（原来）所在的Folder中删除
    for(auto f:lhs.folders)
        f->remMsg(&lhs);
    for(auto f:rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);         //使用swap(set&, set&)
    swap(lhs.contents, rhs.contents);       //swap(string&, string&)
    //将每个message的指针添加到它的新的folder中
    for(auto f:lhs.folders)
        f->addMsg(&lhs);
    for(auto f:rhs.folders)
        f->addMsg(&rhs);
    
}
void Message::save(Folder &f){
    folders.insert(&f);         //将给定Folder添加到我们的Folder列表中
    f.addMsg(this);             //将本Message添加到f的Message集合中
}

void Message::remove(Folder &f){
    folders.erase(&f);          //将给定Folder从我们的Folder列表中删除
    f.remMsg(this);             //将本Message从f的Message集合中删除
}

void Message::add_to_Folders(const Message &m){
    for(auto f:m.folders)       //对每个包含m的Folder
        f->addMsg(this);        //向该Folder添加一个指向本Message的指针
}

Message::Message(const Message &m):
    contents(m.contents),folders(m.folders){
        add_to_Folders(m);      //将本消息添加到指向m的Folder中
    }

void Message::remove_from_Folders(){
    for(auto f:folders)         //对所有的folders中每个指针
        f->remMsg(this);        //从该Folder中删除本Message
}

/*注意：在写拷贝赋值的时候要考虑到自赋值情况*/
Message& Message::operator=(const Message &rhs){
    
    //通过先删除指针再插入它们来处理自赋值情况(??)
    remove_from_Folders();       //更新已有Folder
    contents = rhs.contents;    //从rhs拷贝消息内容
    folders = rhs.folders;      //从rhs拷贝Folders指针
    //相当于自己等于自己
    add_to_Folders(rhs);        //将本Message添加到那些Folder中
    /*处理自赋值的方法就是：先删除再加入*/

    return *this;
}

Message:: Message(Message &&m):contents(std::move(m.contents)){
    move_Folders(&m);//移动folders并更新Folder指针
}

void Message::move_Folders(Message *m){
    folders = std::move(m->folders);    //使用set的移动赋值运算符
    for(auto f:folders){                //对每个Folder
        f->remMsg(m);                   //将Folder中删除旧Message
        f->addMsg(this);                //将本Message添加到Folder中
    }
    m->folders.clear();                 //确保销毁m是无害的
}

Message::~Message(){
    remove_from_Folders();
    cout<<"we are invoking ~Message()"<<endl;
}

int main(){
    Message a("this is a message");
    Folder  folder1("text");
    a.save(folder1);
    a.remove(folder1);
    a.print();
    a.print_folders();

    return 0;
}