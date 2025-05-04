#pragma once
#include "Date.h"

// every slot = 1 hour from 0 - 23
class Slot
{
	long long courtID, slotID; 
	Date date;
public:
	Slot();
	Slot(long long CourtId, long long SlotId, Date Date);

	void setCourtID(long long CourtId);
	void setSlotID(long long SlotId);
	void setDate(const Date& Date);

	long long getCourtID() const;
	long long getSlotID() const;
	Date getDate() const;

	// Operator Overloading
	bool operator == (const Slot& slot) const;
	bool operator < (const Slot& slot) const;
};