///////////////////////////////////////////////////////////////////////
// Group Members: Andrew Hutson, McKenna Galle, Vina Le
// Assignment and Course: CS 473 Final Project
// Date Modified: 11/29/2017
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include"Building.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int num_classes = 0; // variable to store the number of classes the student is taking
	cout << "How many classes are you taking? ";
	cin >> num_classes;

	cout << "You entered " << num_classes << " classes." << endl; // for debugging

	cout << endl; // endline for formatting
	system("PAUSE"); // pauses the program so that the user can see any information on the screen before the probram exits
	return 0;
}