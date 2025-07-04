#ifndef CONTACTNODE_H
#define CONTACTNODE_H

#include <iostream>
#include <string>

using namespace std;

class ContactNode{
	private:
	
	string name;
	string phoneNumber;
	ContactNode* next = 0;
	
	public:
	
	ContactNode(string thatName, string thatNumber);
	void InsertAfter(ContactNode* that);
	string GetName();
	string GetPhoneNumber();
	ContactNode* GetNext();
	void PrintContactNode();
	
};

#endif