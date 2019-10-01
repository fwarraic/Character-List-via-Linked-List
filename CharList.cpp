#include <iostream>
#include <string>
#include"CharList.h"

using namespace std;


// is list empty?
bool CharList::empty() 
{ 
	return (header->next == trailer); 
}

// calculates the size of the list
int CharList::size()
{
	Node* node;
	int count = 0;

	node = header;
	while(node->next != trailer)
	{
		count++;
		node = node->next;
	}

	return count;

}

// insert new node before v
void CharList::add(Node* v, const char& c) 
{ 
	Node* u = new Node; 
	u->data = c; // create a new node for c
	u->next = v; // link u in between v
	u->prev = v->prev; // . . .and v->prev
	v->prev->next = u;
    v->prev = u;
}

// inserts at the front of list
void CharList::insert(char c)
{
	add(header->next, c);
}

// inserts at the back of the list
void CharList::append(char c)
{
	add(trailer, c);
}

// inserts c immediately before the first occurance of d, or
// at the end of the list if d does not occur.
void CharList::insert(char c, char d)
{
	Node* node;
	node = header;

	while(node->next != trailer)
	{
		if (node->data == d)
		{
			add(node, c);
			break;
		}

		node = node->next;
	}

	if ((node->next == trailer) && (node->data == d))
	{
		add(node, c);
	}

	if (node->data != d)
	{
		append(c);
	}
	
}

// inserts c immediately after the first occurance of d, or
// at the end of the list if d does not occur.
void CharList::append(char c, char d)
{
	Node* node;
	node = header;

	while(node->next != trailer)
	{
		if (node->data == d)
		{
			add(node->next, c);
			break;
		}
		node = node->next;
	}

	if ((node->next == trailer) && (node->data == d))
	{
		add(node->next, c);
	}

	if (node->data != d)
	{
		append(c);
	}
}

// inserts c immediately before the nth occurance of d, or
// at the end of the list if d does not occur n times.
void CharList::insert(char c, char d, int n)
{
	Node* node;
	node = header;
	int count = 0;

	while(node->next != trailer)
	{
		if (node->data == d)
		{
			count++;
		}

		if ((node->data == d) && (count == n))
		{
			add(node, c);
			break;
		}
		node = node->next;
	}

	if ((node->next == trailer) && (node->data == d))
	{
		add(node, c);
	}

	if (node->data != d)
	{
		append(c);
	}
}

// inserts c immediately after the nth occurance of d, or
// at the end of the list if d does not occur n times.
void CharList::append(char c, char d, int n)
{
	Node* node;
	node = header;
	int count = 0;

	while(node->next != trailer)
	{
		if (node->data == d)
		{
			count++;
		}

		if ((node->data == d) && (count == n))
		{
			add(node->next, c);
			break;
		}
		node = node->next;
	}

	if ((node->next == trailer) && (node->data == d))
	{
		add(node->next, c);
	}

	if (node->data != d)
	{
		append(c);
	}
} 


// remove node v
void CharList::removeN(Node* v) 
{ 
	Node* u = v->prev; // predecessor
	Node* w = v->next; // successor
	u->next = w; // unlink v from list
	w->prev = u;
	delete v;
}



// delete the first occurance of character c. Do nothing if
// c does not occur.
void CharList::remove(char c)
{
	Node* node;
	node = header;

	while(node->next != trailer)
	{
		if (node->data == c)
		{
			removeN(node);
			break;
		}
		node = node->next;
	}
} 

// delete the nth occurance of c. Do nothing if c does not
// occur n times.
void CharList::remove(char c, int n)
{
	Node* node;
	node = header;
	int count = 0;

	while(node->next != trailer)
	{
		if (node->data == c)
		{
			count++;
		}

		if ((node->data == c) && (count == n))
		{
			removeN(node);
			break;
		}
		node = node->next;
	}
} 

// return the list as a string.
string CharList::toString()
{
	Node* node;
	node = header;
	string word;

	while(node->next != trailer)
	{
		node = node->next;
		word += node->data;
	}

	return word;
}

// constructor
CharList::CharList(string s) 
{ 
	string word = s;

	// create sentinels
	header = new Node; 
	trailer = new Node;

	// have them point to each other
	header->next = trailer; 
	trailer->prev = header;

	Node* node;
	
	for (int i = 0; i < word.length(); ++i)
	{
		add(trailer, word[i]);
	}


}

// remove from font
void CharList::removeFront() 
{ 
	removeN(header->next); 
}

// destructor
CharList::~CharList()
{
	// remove all but sentinels
	while (header->next != trailer)
	{
		removeFront();
	} 

	// remove the sentinels 
	delete header; 
	delete trailer;
}

