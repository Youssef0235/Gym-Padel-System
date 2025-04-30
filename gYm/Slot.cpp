#include "Slot.h"

//Constructors
Slot::Slot() {}
Slot::Slot(int cid, int sid, Date dt)
{
	courtID = cid;
	slotID = sid;
	date = dt;
}

//Setters
void Slot::setMemberID(int id)
{
	memberID = id;
}
void Slot::setCourtID(int cid)
{
	courtID = cid;
}
void Slot::setSlotID(int sid)
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
int Slot::getMemberID()
{
	return memberID;
}
int Slot::getCourtID()
{
	return courtID;
}
int Slot::getSlotID()
{
	return slotID;
}
Date Slot::getDate()
{
	return date;
}