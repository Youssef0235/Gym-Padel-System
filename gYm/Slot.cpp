#include "Slot.h"

//Constructors
Slot::Slot() : memberID(0), courtID(0), slotID(0) {}

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
void Slot::setDate(const Date& Date) 
{
	date = Date;
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

bool Slot::operator == (const Slot& slot)
{
	return courtID == slot.courtID and
		date == slot.date and
		slotID == slot.slotID;
}
