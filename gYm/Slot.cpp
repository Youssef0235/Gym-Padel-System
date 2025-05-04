#include "Slot.h"

Slot::Slot() : courtID(0), slotID(0) {}

Slot::Slot(long long CourtId, long long SlotId, Date Date)
{
	courtID = CourtId;
	slotID = SlotId;
	date = Date;
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

long long Slot::getCourtID() const
{
	return courtID;
}

long long Slot::getSlotID() const
{
	return slotID;
}

Date Slot::getDate() const
{
	return date;
}

bool Slot::operator == (const Slot& slot) const
{
	return courtID == slot.courtID and
		date == slot.date and
		slotID == slot.slotID;
}

bool Slot::operator<(const Slot& slot) const
{
	return slotID < slot.slotID;
}
