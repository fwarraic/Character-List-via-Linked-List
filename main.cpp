#include<iostream>
#include"CharList.h"

using namespace std;

//Testing the empty() method
void testEmpty()
{
	cout << "Test for empty() : ";
	string s = "Hello";
	CharList List(s);

	if (List.empty() == 0)
	{
		cout << "passed" << endl;
	}
	else if (List.empty() == 1)
	{
		cout << "passed" << endl;	
	}
	else{
		cout << "failed" << endl;
	}
}

//Testing the size() method
void testSize()
{
	cout << "Test for size() : ";
	string s = "Hello";
	CharList List(s);

	if (List.size() == s.length())
	{
		cout << "passed" << endl;
	}
	else{
		cout << "failed" << endl;
	}
}

//Testing the insert(c) method
void testInsert()
{
	cout << "Test for insert(c): ";
	string s = "Hello";
	CharList List(s);
	List.insert('a');
	s = 'a' + s;

	if (List.toString() == s)
	{
		cout << "passed" << endl;
	}
	else{
		cout << "failed" << endl;
	}


	cout << "Test for insert(c, d): ";
	s = "Hello";
	CharList List1(s);
	List1.insert('x' , 'l');
	string t = "Hexllo";

	if (List1.toString() == t)
	{
		cout << "passed" << endl;
	}
	else{
		cout << "failed" << endl;
	}


	cout << "Test for insert(c, d, n): ";
	s = "HelloBell";
	CharList List2(s);
	List2.insert('x', 'l', 3);
	t = "HelloBexll";

	if (List2.toString() == t)
	{
		cout << "passed" << endl;
	}
	else{
		cout << "failed" << endl;
	}

}

//Testing the append(c) method
void testAppend()
{
	cout << "Test for append(c): ";
	string s = "Hello";
	CharList List(s);
	List.append('a');
	s += 'a';

	if (List.toString() == s)
	{
		cout << "passed" << endl;
	}
	else{
		cout << "failed" << endl;
	}


	cout << "Test for append(c, d): ";
	s = "Hello";
	CharList List1(s);
	List1.append('x', 'l');
	string t = "Helxlo";

	if (List1.toString() == t)
	{
		cout << "passed" << endl;
	}
	else{
		cout << "failed" << endl;
	}


	cout << "Test for append(c, d, n): ";
	s = "lululemon";
	CharList List2(s);
	List2.append('x', 'l', 2);
	t = "lulxulemon";

	if (List2.toString() == t)
	{
		cout << "passed" << endl;
	}
	else{
		cout << "failed" << endl;
	}
}

//Testing the remove() method
void testRemove()
{
	//Testing the remove(c) method
	cout << "Test for remove(c): ";
	string s = "Hello";
	CharList List(s);
	List.remove('e');
	s = "Hllo";

	if (List.toString() == s)
	{
		cout << "passed" << endl;
	}
	else{
		cout << "failed" << endl;
	}


	// Testing the remove(c, n) method
	cout << "Test for remove(c, n): ";
	s = "lululemon";
	CharList List1(s);
	List1.remove('l', 3);
	string t = "luluemon";

	if (List1.toString() == t)
	{
		cout << "passed" << endl;
	}
	else{
		cout << "failed" << endl;
	}	
}

int main() {
	cout << "Welcome to CharList :)" << endl;
	cout << "Following are the tests:" << endl;
	
	cout << endl;
	testEmpty();
	testSize();
	testInsert();
	testAppend();
	testRemove();
	cout << endl;

	
	
	return 0;
}
