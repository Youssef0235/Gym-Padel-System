#pragma once
#include "Date.h"

// every slot = 1 hour from 0 - 23
class Slot
{
	long long memberID, courtID, slotID; 
	Date date;
public:
	Slot();
	Slot(long long CourtId, long long SlotId, Date Date);

	void setMemberID(long long id);
	void setCourtID(long long CourtId);
	void setSlotID(long long SlotId);
	void setDate(const Date& Date);

	long long getMemberID();
	long long getCourtID();
	long long getSlotID();
	Date getDate();

	// Operator Overloading
	bool operator == (const Slot& slot);
};