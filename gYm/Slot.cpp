#include "Slot.h"

//Constructors
Slot::Slot() {}

Slot::Slot(long long cid, long long sid, Date dt)
{
	courtID = cid;
	slotID = sid;
	date = dt;
}

//Setters
void Slot::setMemberID(long long id)
{
	memberID = id;
}
void Slot::setCourtID(long long cid)
{
	courtID = cid;
}
void Slot::setSlotID(long long sid)
{
	slotID = sid;
}
void Slot::setDate(int d, int m, int y)
{
	date.setDay(d);
	date.setMonth(m);
	date.setYear(y);
}

//Getters
long long Slot::getMemberID()
{
	return memberID;
}

long long Slot::getCourtID()
{
	return courtID;
}

long long Slot::getSlotID()
{
	return slotID;
}

Date Slot::getDate()
{
	return date;
}