#ifndef _13_33_H_
#define _13_33_H_

#include <string>
#include <set>

using namespace std;

class Message;
class Folder {
	friend class Message;
public:
	explicit Folder(const string& input) :dir_name(input) {
		cout << "we are invoking Folder constructer." << endl;
	}
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();

	void addMsg(Message*);
	void remMsg(Message*);

	void print() {
		cout << "the folder is" << dir_name << endl;
	}
private:
	string dir_name;
	set<Message*>messages;
	void add_to_Msgs(const Folder&);
	void remove_from_Msgs();
};

class Message {
	friend class Folder;
	friend void swap(Message& lhs, Message& rhs);
public:
	//���캯����folders����ʽ��ʼ��Ϊ�ռ���
	explicit Message(const string& str = "") :
		contents(str) {
		cout << "we are invoking message constructer." << endl;
	}
	//�������캯�����������Ƴ�Ա����������ָ��Message��ָ��
	Message(const Message&);
	//������ֵ�����
	Message& operator=(const Message&);
	//�ƶ����캯��
	Message(Message&& m) :contents(std::move(m.contents));
	//�ƶ���ֵ�����
	Message& operator=(Message&& rhs) {
		if (this != &rhs) {//ֱ�Ӽ���Ը�ֵ���
			remove_from_Folders();              //����������
			contents = std::move(rhs.contents); //�ƶ���ֵ�����
			move_Folders(&rhs);                 //����Foldersָ��Message
		}
		return *this;
	}
	//��������
	~Message();
	//�Ӹ���Folder���������/ɾ����Message
	void save(Folder&);
	void remove(Folder&);
	void move_Folders(Message* m);

	void print() {
		cout << "the message is:" << contents << endl;
	}
	void print_folders() {
		for (auto f : folders) {
			cout << f->dir_name << endl;
		}
	}
private:
	string contents;                        //ʵ����Ϣ�ı�
	set<Folder*>folders;                    //������Message��Folder
	//�������캯����������ֵ�����������������ʹ�õĹ��ߺ���
	//����Message��ӵ�ָ�������Folder��
	void add_to_Folders(const Message&);
	//��folders�е�ÿ��Folder��ɾ����Message
	void remove_from_Folders();
};

#endif