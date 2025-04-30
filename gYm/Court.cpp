#include "Court.h"

//Constructors
Court::Court() : courtId(0) {}


Court::Court(int id, std::string loc)
{
	courtId = id;
	location = loc;
}

//Setters
void Court::setID(long long Courtid)
{
	courtId = Courtid;
}
void Court::setLocation(string loc)
{
	location = loc;
}

//Getters
long long Court::getID()
{
	return courtId;
}

string Court::getLocation()
{
	return location;
}