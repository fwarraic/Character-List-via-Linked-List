#ifndef CHARLIST_H
#define CHARLIST_H

#include <iostream>
#include <string>

using namespace std;


class Node { // doubly linked list node
private:
	char data; // node element value
	Node* prev; // previous node in list
	Node* next; // next node in list

	friend class CharList; // allow CharList access

};

class CharList{
public:
	bool empty(); // is the list empty?

	int size(); // the number of elements in the list

	void insert(char c); // inserts the character c at the front of the list

	void append(char c); // inserts the character c at the back of the list
	
	void insert(char c, char d); // inserts c immediately before the first occurance of d, or
								// at the end of the list if d does not occur.
	
	void append(char c, char d); // inserts c immediately after the first occurance of d, or
								// at the end of the list if d does not occur.
	
	void insert(char c, char d, int n);// inserts c immediately before the nth occurance of d, or
										// at the end of the list if d does not occur n times.
	
	void append(char c, char d, int n); // inserts c immediately after the nth occurance of d, or
										// at the end of the list if d does not occur n times.
	
	void remove(char c); // delete the first occurance of character c. Do nothing if
						// c does not occur.
	
	void remove(char c, int n); // delete the nth occurance of c. Do nothing if c does not
								// occur n times.
	
	string toString(); // return the list as a string.
	
	CharList(string s); // constructor. Initializes the list to the contents of the string.
	
	~CharList(); // destructor. Returns all memory in the list

	void removeFront(); // remove from front

private: // local type definitions
	Node* header; // list sentinels
	Node* trailer;

protected: // local utilities
	void add(Node* v, const char& c); // insert new node before v
	void removeN(Node* v); // remove node v

};

#endif