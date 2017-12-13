#ifndef BUILDING_H_
#define BUILDING_H_

#include<string>

using std::string;

class Building
{
private:
	int ID; // building identification number
	string name; // name of the building
	int num_connections; // the number of other buildings that connect to the building

public:
	// constructor
	Building(); // default constructor
	Building(int, string, int); // takes in building ID, name, and number of connections
	// getters and setters
	int getID();
	void setID(int);
	string getName();
	void setName(string);
	int getNum_connections();
	void setNum_connections(int);

};

#endif