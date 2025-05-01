#pragma once
#include "Date.h"

class Slot
{
	int memberID;
	int courtID;
	int slotID; // every slot = 1 Hour from 0 - 23
	Date date;
public:
	Slot();
	Slot(int, int, Date);

	void setMemberID(int id);
	void setCourtID(int);
	void setSlotID(int);
	void setDate(int, int, int);

	int getMemberID();
	int getCourtID();
	int getSlotID();
	Date getDate();

};