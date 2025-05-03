#include "BookingSystem.h"
#include <ctime>

void BookingSystem::addCourt(int cid, string loc)
{
	Court cnew(cid, loc, "");
	courts.push_back(cnew);
}

Slot BookingSystem::searchAvailableCourts(Date date, int sid, string loc)
{
	long long id = -1;
	for (auto& court : courts) 
	{
		if (loc == court.getLocation()) 
			id = court.getID();
	}
	Date newDate = date;
	while (true) 
	{
		Slot candidateSlot(id, sid, newDate);
		bool found = false;
		for (auto& slot : slots)
		{
			// Search in the booked slots
			if (slot == candidateSlot)
			{
				found = false;
				break;
			}
		}
		if (!found) 
		{
			// Slot is available
			return Slot(id, sid, date);
		}
		// Search for the next hour (sid == hours from 0 to 23
		sid++;
		if (sid == 24)
		{
			sid = 0;
			newDate = Date::getNextDate(newDate);
		}
	}
}

void BookingSystem::checkSlotTimePassed(vector<Slot>& slots)
{
	vector<Slot>::iterator tempS;
	for (tempS = slots.begin(); tempS != slots.end(); tempS++)
	{
		tm targetTime = {};
		targetTime.tm_mday = (*tempS).getDate().getDay();
		targetTime.tm_mon = ((*tempS).getDate().getMonth()) - 1;  // tm_mon is 0-based (0 = Jan)
		targetTime.tm_year = ((*tempS).getDate().getYear()) - 1900; // tm_year is years since 1900
		targetTime.tm_hour = (*tempS).getSlotID();
		targetTime.tm_min = 0;
		targetTime.tm_sec = 0;

		time_t target = mktime(&targetTime);

		time_t now = time(0);

		double hoursDiff = difftime(target, now) / 3600.0;

		if (hoursDiff < 0) {
			slots.erase((tempS));
		}
	}
}

void BookingSystem::makeBooking(Slot s, int mID)
{
	s.setMemberID(mID);
	slots.push_back(s);
}

bool BookingSystem::cancelBooking(int sid)
{
	vector<Slot>::iterator tempS;
	for (tempS = slots.begin(); tempS != slots.end(); tempS++)
	{
		if (sid == (*tempS).getSlotID())
		{
			tm targetTime = {};
			targetTime.tm_mday = (*tempS).getDate().getDay();
			targetTime.tm_mon = ((*tempS).getDate().getMonth()) - 1;  // tm_mon is 0-based (0 = Jan)
			targetTime.tm_year = ((*tempS).getDate().getYear()) - 1900; // tm_year is years since 1900
			targetTime.tm_hour = sid;
			targetTime.tm_min = 0;
			targetTime.tm_sec = 0;

			time_t target = mktime(&targetTime);

			time_t now = time(0);

			double hoursDiff = difftime(target, now) / 3600.0;

			if (hoursDiff > 3) {
				slots.erase((tempS));
				return 1;
			}
			else {
				return 0; //GUI
			}
		}
	}
	return 0;
}