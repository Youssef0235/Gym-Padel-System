#include "BookingSystem.h"
#include <ctime>

void BookingSystem::addCourt(int cid, string loc)
{
	Court cnew(cid, loc);
	courts.push_back(cnew);
}

Slot BookingSystem::searchAvailableCourts(int d, int m, int y, int sid, string loc)
{
	int id = -1; //Location Error
	vector<Court>::iterator tempC;
	for (tempC = courts.begin(); tempC != courts.end(); tempC++)
	{
		if (loc == (*tempC).getLocation())
		{
			id = (*tempC).getID();
		}
	}

	vector<Slot>::iterator tempS;
	for (tempS = slots.begin(); tempS != slots.end(); tempS++)
	{

		if (!((*tempS).getCourtID() == id &&
			(*tempS).getDate().getDay() == d &&
			(*tempS).getDate().getMonth() == m &&
			(*tempS).getDate().getYear() == y &&
			(*tempS).getSlotID() == sid))
		{
			//Availavble
			return (*tempS);
		}
		else
		{
			sid++;

			if (sid >= 23)
			{
				d++;
				sid = -1;
			}
			if (d > 30)
			{
				m++;
				d = 1;
			}
			if (m > 12)
			{
				y++;
				m = 1;
			}
			//Not Available & return the next closest slot
			return searchAvailableCourts(d, m, y, sid, loc);

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

}