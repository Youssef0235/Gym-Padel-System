#include "Court.h"

Court::Court() : courtId(0) {}

Court::Court(long long CourtId, string CourtLocation, string CourtName)
{
	courtId = CourtId;
	courtLocation = CourtLocation;
	courtName = CourtName;
}

void Court::setID(long long Courtid)
{
	courtId = Courtid;
}

void Court::setLocation(string CourtLocation)
{
	courtLocation = CourtLocation;
}

void Court::setName(string CourtName)
{
	courtName = CourtName;
}

long long Court::getID() const
{
	return courtId;
}

string Court::getLocation() const
{
	return courtLocation;
}

string Court::getName() const
{
	return courtName;
}
