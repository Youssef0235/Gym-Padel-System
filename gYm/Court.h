#pragma once
#include <iostream>
using namespace std;

class Court
{
private:
	long long courtId;
	string courtLocation, courtName;
public:
	Court();
	Court(long long CourtId, string CourtLocation, string CourtName);

	void setID(long long CourtId);
	void setLocation(string CourtLocation);
	void setName(string CourtName);

	long long getID() const;
	string getLocation() const;
	string getName() const;
};