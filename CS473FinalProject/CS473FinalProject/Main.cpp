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
	cout << "How many buildings will be in your route? ";
	cin >> num_classes;

	cout << "You entered " << num_classes << " building(s)." << endl; // for debugging

	cout << endl; // endline for formatting

	// Building object creation
	Building Johnston(1, "Johnston", 35);
	Building Robinson(2, "Robinson", 24);
	Building Library(3, "Library", 24);
	Building Hendricks(4, "Hendricks", 25);
	Building HUB(5, "The HUB", 26);
	Building Lindaman(6, "Lindaman", 26);
	Building Weyerhaeuser(7, "Weyerhaeuser", 22);
	Building Dixon(8, "Dixon", 23);
	Building Cowles(9, "Cowles Auditorium", 23);
	Building Music(10, "Music Building", 22);
	Building Westminster(11, "Westminster", 22);
	Building Art(12, "Art Building", 23);
	Building Hawthorne(13, "Hawthorne", 22);
	Building Stewart(14, "Stewart", 16);
	Building Arend(15, "Arend", 14);
	Building BJ(16, "Baldwin-Jenkins", 14);
	Building Oliver(17, "Oliver", 17);
	Building Duvall(18, "Duvall", 14);
	Building Boppell(19, "Boppell", 14);
	Building Warren(20, "Warren", 14);
	Building Mac(21, "McMillan", 14);
	Building Ballard(22, "Ballard", 14);

	// Building object creation debugging
	cout << "Building '" << Johnston.getName() << "' has ID '" << Johnston.getID() << "' and " << Johnston.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Robinson.getName() << "' has ID '" << Robinson.getID() << "' and " << Robinson.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Library.getName() << "' has ID '" << Library.getID() << "' and " << Library.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Hendricks.getName() << "' has ID '" << Hendricks.getID() << "' and " << Hendricks.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << HUB.getName() << "' has ID '" << HUB.getID() << "' and " << HUB.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Lindaman.getName() << "' has ID '" << Lindaman.getID() << "' and " << Lindaman.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Weyerhaeuser.getName() << "' has ID '" << Weyerhaeuser.getID() << "' and " << Weyerhaeuser.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Dixon.getName() << "' has ID '" << Dixon.getID() << "' and " << Dixon.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Cowles.getName() << "' has ID '" << Cowles.getID() << "' and " << Cowles.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Music.getName() << "' has ID '" << Music.getID() << "' and " << Music.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Westminster.getName() << "' has ID '" << Westminster.getID() << "' and " << Westminster.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Art.getName() << "' has ID '" << Art.getID() << "' and " << Art.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Hawthorne.getName() << "' has ID '" << Hawthorne.getID() << "' and " << Hawthorne.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Stewart.getName() << "' has ID '" << Stewart.getID() << "' and " << Stewart.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Arend.getName() << "' has ID '" << Arend.getID() << "' and " << Arend.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << BJ.getName() << "' has ID '" << BJ.getID() << "' and " << BJ.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Oliver.getName() << "' has ID '" << Oliver.getID() << "' and " << Oliver.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Duvall.getName() << "' has ID '" << Duvall.getID() << "' and " << Duvall.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Boppell.getName() << "' has ID '" << Boppell.getID() << "' and " << Boppell.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Warren.getName() << "' has ID '" << Warren.getID() << "' and " << Warren.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Mac.getName() << "' has ID '" << Mac.getID() << "' and " << Mac.getNum_connections() << " connections to other buildings." << endl;
	cout << "Building '" << Ballard.getName() << "' has ID '" << Ballard.getID() << "' and " << Ballard.getNum_connections() << " connections to other buildings." << endl;

	cout << endl; // endline for formatting
	system("PAUSE"); // pauses the program so that the user can see any information on the screen before the probram exits
	return 0;
}