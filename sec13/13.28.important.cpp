#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TreeNode{
    public:
        //下面这个初始化函数代码，是抄的网上的
        TreeNode():value(string()),count(new int(1)),left(NULL),right(NULL){
            cout<<"we at the create function."<<endl;
        }
        /*注意这里写的拷贝函数，拷贝！拷贝！分清是：指针型的类！
        TreeNode(const TreeNode& obj):value(obj.value),count(new int(1)){
            cout<<"we at the copy function"<<endl;
            *(this->count) = 1;
            (*obj.count)++;
            
            value = obj.value;
            left = obj.left;
            right = obj.right;
            cout<<"copy function done."<<endl;
        }
        */
       //以下代码是抄的网上的
       TreeNode(const TreeNode& obj):value(obj.value),count(obj.count),left(obj.left),right(obj.right){
           ++*obj.count;
       }
       //下面代码是抄的网上的
        TreeNode& operator=(const TreeNode& obj){

            //=右边的对象又要被多引用一次
            ++(*obj.count);
            //=左边的对象要指向别的对象，所以--自己目前引用的对象，如果--到0就释放没有减到0就不释放
            if(--*this->count == 0){
                delete this->count;
                delete this->left;
                delete this->right;
            }
            //=左边的对象开始指向=右边对象引用的内存地方
            count = obj.count;
            value = obj.value;
            left = obj.left;
            right = obj.right;
            return *this;   

        }
        ~TreeNode(){
            delete count;
            delete left;
            delete right;
        }
    private:
        string value;
        int    *count;
        TreeNode *left;
        TreeNode *right;
};
class BinStrTree{
    public:
        /*以下一小段是自己写的错了
        BinStrTree():root(new TreeNode()){};
        BinStrTree(const TreeNode*& input_node):root(input_node){};
        BinStrTree& operator=(const TreeNode*& input_node){
            root(input_node);
            return *this;
        }
        ~BinStrTree(){
            delete root;
        }
        */
       //以下一段是自己参照的网上的写的
        BinStrTree():root(new TreeNode()){};
        BinStrTree(const BinStrTree& obj):root(new TreeNode(*obj.root)){};
        /*自己下面的拷贝赋值运算符又写错了
        BinStrTree& operator=(const BinStrTree& obj){
            root(new TreeNode(obj.root));
            return *this;
        }
        */
        //重新抄的网上的拷贝赋值函数
        BinStrTree& BinStrTree::operator=(const BinStrTree& bst){
            TreeNode *new_root = new TreeNode(*bst.root);
            /*
                1.这里使用了TreeNode中的拷贝构造函数，也就是类中类的拷贝和引用
                2.这里也用了一个非常重要的准则，就是在写拷贝赋值运算符的时候，定义一个中间变量。
                3.注意这里使用的是*bst.root（原因要使用TreeNode类中的定义的拷贝构造函数来进行变量的拷贝引用<合适?>）
            */

            delete root;
            root = new_root;
            return *this;
        }
        ~BinStrTree(){
            delete root;
        }
    private:
        TreeNode *root;
};

int main(){

    TreeNode node_root;
    cout<<"we create the node_root"<<endl;
    TreeNode node1(node_root);
    cout<<"we create the node1"<<endl;
    return 0;

}