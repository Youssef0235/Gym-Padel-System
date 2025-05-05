#pragma once
#include "Date.h"

// every slot = 1 hour from 0 - 23
class Slot
{
	long long courtID;
	int hour;
	Date date;
public:
	Slot();
	Slot(long long CourtId, int hour, Date Date);

	void setCourtID(long long CourtId);
	void setHour(int hour);
	void setDate(const Date& Date);

	long long getCourtID() const;
	int getHour() const;
	Date getDate() const;

	// Operator Overloading
	bool operator == (const Slot& slot) const;
};