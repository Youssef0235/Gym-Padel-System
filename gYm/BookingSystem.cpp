#include "BookingSystem.h"
#include <ctime>

bool BookingSystem::isSlotAvailable(const Slot& slot)
{
	auto it = FileManager::members.begin();
	while (it != FileManager::members.end())
	{
		bool exist = (FileManager::foundSlot(it->first, slot));
		if (exist)
			return false;
		it++;
	}
	return true;
}

Slot BookingSystem::searchNext(Date date, int slotId, string location)
{
	long long courtId = FileManager::getCourtId(location);
	Date newDate = date;
	Slot candidateSlot;
	auto it = FileManager::members.begin();
	while (it != FileManager::members.end())
	{
		vector<Slot> st =  FileManager::members[it->first].getSlots();
		candidateSlot = Slot(courtId, slotId, newDate);
		bool available = isSlotAvailable(candidateSlot);
		if (available)
			break;
		else
		{
			slotId++;
			if (slotId == 24)
			{
				// Check Next Day
				newDate = Date::getNextDate(newDate);
				slotId = 0;
			}
		}
		it++;
	}
	return candidateSlot;
}

void BookingSystem::checkSlotTimePassed()
{
	auto it = FileManager::members.begin();
	while (it != FileManager::members.end())
	{
		vector<Slot>memberReservedSlots = FileManager::members[it->first].getSlots();
		for(int i = 0; i < memberReservedSlots.size(); i++)
		{
			tm targetTime = {};
			targetTime.tm_mday = memberReservedSlots[i].getDate().getDay();
			targetTime.tm_mon = memberReservedSlots[i].getDate().getMonth() - 1;  // tm_mon is 0-based (0 = Jan)
			targetTime.tm_year = memberReservedSlots[i].getDate().getYear() - 1900; // tm_year is years since 1900
			targetTime.tm_hour = memberReservedSlots[i].getHour();
			targetTime.tm_min = 0;
			targetTime.tm_sec = 0;
			time_t target = mktime(&targetTime);
			time_t now = time(0);
			double hoursDiff = difftime(target, now) / 3600.0;
			if (hoursDiff < 0)
				FileManager::removeSlot(it->first, memberReservedSlots[i]);
		}
		it++;
	}
}

void BookingSystem::makeBooking(Slot& slot, long long memberId)
{
	FileManager::members[memberId].addSlot(slot);
}

bool BookingSystem::cancelBooking(long long memberId, Slot slot)
{

	tm targetTime = {};
	targetTime.tm_mday = slot.getDate().getDay();
	targetTime.tm_mon = slot.getDate().getMonth() - 1;  // tm_mon is 0-based (0 = Jan)
	targetTime.tm_year = slot.getDate().getYear() - 1900; // tm_year is years since 1900
	targetTime.tm_hour = slot.getHour();
	targetTime.tm_min = 0;
	targetTime.tm_sec = 0;

	time_t target = mktime(&targetTime);

	time_t now = time(0);

	double hoursDiff = difftime(target, now) / 3600.0;

	if (hoursDiff > 3) 
	{
		FileManager::removeSlot(memberId, slot);
		return true;
	}
	return false;
}