#pragma once
#include "Date.h"

class Slot
{
	long long memberID, courtID, slotID; // every slot = 1 Hour from 0 - 23
	Date date;
public:
	Slot();
	Slot(long long, long long, Date);

	void setMemberID(long long id);
	void setCourtID(long long);
	void setSlotID(long long);
	void setDate(int, int, int);

	long long getMemberID();
	long long getCourtID();
	long long getSlotID();
	Date getDate();
};