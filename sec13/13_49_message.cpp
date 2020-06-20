#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "13_49_message.hpp"

using namespace std;
/*

	message->�����ʼ�
	folder ->��ϢĿ¼
	ע�⣺
	1. Ϊ�˼�¼messageλ����Щfolder�У�ÿ��message���ᱣ��һ��������folder
	��ָ���set��ͬ���ģ�ÿ��folder������һ����������message��ָ���set
	2. �۲���Щ���������ǿ��Կ��������������Ϳ�����ֵ�����������Ӱ���һ��message
	������folder��ɾ���������Ƶģ��������캯���Ϳ�����ֵ�������Ҫ��һ��message
	��ӵ�������һ��folder�С����ǽ���������private�Ĺ��ߺ����������Щ������
	3.������ֵ�����ͨ��ִ�п������캯��������������ҲҪ���Ĺ�������������£�����
	�Ĺ���Ӧ�÷���private�Ĺ��ߺ�������ɡ�

*/

/*ע�⣺�ú�д�������캯���͸�ֵ������������������������Ҫ*/
/******************************** Folder *******************************/
Folder::Folder(const Folder& folder_c) {
	messages = folder_c.messages;
	for (auto msg : messages) {
		msg->save(*this);
	}
}

Folder& Folder::operator=(const Folder& folder_c) {

	messages = folder_c.messages;
	//???????�����ܷ�ֹ�Ը�ֵ��������������
	return *this;
}

Folder::~Folder() {
	cout << "we are invoking ~Folder()" << endl;
}

void Folder::add_to_Msgs(const Folder& f) {
	for (auto m : f.messages) {
		m->folders.insert(this);
	}
}

void Folder::remove_from_Msgs() {
	for (auto m : messages)
		m->folders.erase(this);
}

void Folder::addMsg(Message* message) {
	this->messages.insert(message);
}

void Folder::remMsg(Message* message) {
	/*
	auto item = this->messages.find(message);
	if( item != messages.end() ){
		this->messages.erase(item);
	};
	*/
	//���ϴ������Լ�д�ģ�������࣬û���պ�erase�÷�
	messages.erase(message);
}


/******************************** Message *******************************/
inline
void swap(Message& lhs, Message& rhs) {
	using std::swap;                        //�ڱ������ϸ���˵������Ҫ��
											//������һ����ϰ��
	//��ÿ����Ϣ��ָ�������ԭ�������ڵ�Folder��ɾ��
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.folders, rhs.folders);         //ʹ��swap(set&, set&)
	swap(lhs.contents, rhs.contents);       //swap(string&, string&)
	//��ÿ��message��ָ����ӵ������µ�folder��
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);

}
void Message::save(Folder& f) {
	folders.insert(&f);         //������Folder��ӵ����ǵ�Folder�б���
	f.addMsg(this);             //����Message��ӵ�f��Message������
}

void Message::remove(Folder& f) {
	folders.erase(&f);          //������Folder�����ǵ�Folder�б���ɾ��
	f.remMsg(this);             //����Message��f��Message������ɾ��
}

void Message::add_to_Folders(const Message& m) {
	for (auto f : m.folders)       //��ÿ������m��Folder
		f->addMsg(this);        //���Folder���һ��ָ��Message��ָ��
}

Message::Message(const Message& m) :
	contents(m.contents), folders(m.folders) {
	add_to_Folders(m);      //������Ϣ��ӵ�ָ��m��Folder��
}

void Message::remove_from_Folders() {
	for (auto f : folders)         //�����е�folders��ÿ��ָ��
		f->remMsg(this);        //�Ӹ�Folder��ɾ����Message
}

/*ע�⣺��д������ֵ��ʱ��Ҫ���ǵ��Ը�ֵ���*/
Message& Message::operator=(const Message& rhs) {

	//ͨ����ɾ��ָ���ٲ��������������Ը�ֵ���(??)
	remove_from_Folders();       //��������Folder
	contents = rhs.contents;    //��rhs������Ϣ����
	folders = rhs.folders;      //��rhs����Foldersָ��
	//�൱���Լ������Լ�
	add_to_Folders(rhs);        //����Message��ӵ���ЩFolder��
	/*�����Ը�ֵ�ķ������ǣ���ɾ���ټ���*/

	return *this;
}

Message::Message(Message&& m) :contents(std::move(m.contents)) {
	move_Folders(&m);//�ƶ�folders������Folderָ��
}

void Message::move_Folders(Message* m) {
	folders = std::move(m->folders);    //ʹ��set���ƶ���ֵ�����
	for (auto f : folders) {                //��ÿ��Folder
		f->remMsg(m);                   //��Folder��ɾ����Message
		f->addMsg(this);                //����Message��ӵ�Folder��
	}
	m->folders.clear();                 //ȷ������m���޺���
}

Message::~Message() {
	remove_from_Folders();
	cout << "we are invoking ~Message()" << endl;
}

int main() {
	Message a("this is a message");
	Folder  folder1("text");
	a.save(folder1);
	a.remove(folder1);
	a.print();
	a.print_folders();

	return 0;
}