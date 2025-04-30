#pragma once
#include <iostream>
using namespace std;

class Court
{
private:
	long long courtId;
	string location;

public:
	//Constructors
	Court();
	Court(int, string);

	//Setters
	void setID(long long CourtId);
	void setLocation(string Location);

	//Getters
	long long getID();
	string getLocation();
};