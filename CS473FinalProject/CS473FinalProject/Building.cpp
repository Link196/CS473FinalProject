#include "Building.h"

Building::Building()
{
	ID = 0;
	name = "Test";
	num_connections = 0;
}

Building::Building(int id, string starting_name, int connections)
{
	ID = id;
	name = starting_name;
	num_connections = connections;
}

int Building::getID()
{
	return ID;
}

void Building::setID(int newID)
{
	ID = newID;
}

string Building::getName()
{
	return name;
}

void Building::setName(string newName)
{
	name = newName;
}

int Building::getNum_connections()
{
	return num_connections;
}

void Building::setNum_connections(int newNumConnections)
{
	num_connections = newNumConnections;
}