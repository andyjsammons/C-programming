#include "ContactNode.h"
#include <iostream>
#include <string>

using namespace std;



ContactNode::ContactNode(string name, string phoneNumber){
	this->name = name;
	this->phoneNumber = phoneNumber;
}

void ContactNode::InsertAfter(ContactNode* that){
	ContactNode* temp;
	temp = this->next;
	this->next = that;
	that->next = temp;
}

string ContactNode::GetName(){
	return this->name;
}

string ContactNode::GetPhoneNumber(){
	return this->phoneNumber;
}

ContactNode* ContactNode::GetNext(){
	return this->next;
}

void ContactNode::PrintContactNode(){
	cout << "Name: " << this->name << endl;
	cout << "Phone number: " << this->phoneNumber << endl;
}

