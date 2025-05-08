#include "Slot.h"

Slot::Slot() : courtID(-1), hour(-1) {}

Slot::Slot(long long CourtId, int Hour, Date Date)
{
	courtID = CourtId;
	hour = Hour;
	date = Date;
}

void Slot::setCourtID(long long cid)
{
	courtID = cid;
}

void Slot::setHour(int Hour)
{
	hour = Hour;
}

void Slot::setDate(const Date& Date) 
{
	date = Date;
}

long long Slot::getCourtID() const
{
	return courtID;
}

int Slot::getHour() const
{
	return hour;
}

Date Slot::getDate() const
{
	return date;
}

bool Slot::operator == (const Slot& slot) const
{
	return courtID == slot.courtID and
		date == slot.date and
		hour == slot.hour;
}

bool Slot::operator < (const Slot& slot) const
{
	if (date == slot.date)
		return hour < slot.getHour();
	return date < slot.date;
}
