#include "Receptionist.h"

Receptionist::Receptionist() {}

Receptionist::Receptionist(string firstName, string middleName, string lastName, Date dob, long long id, int Salary) : Staff(firstName, middleName, lastName, dob, id, Salary)
{}

void Receptionist::sendRenewalNoti()
{
	int add = 17;
	for (int i = 0; i < FileManager::members.size(); i++)
	{
		if (Date::oneWeekLeft(Date::getTodaysDate(), FileManager::members[add + i].getEndDate()))
		{
			FileManager::members[add + i].pushMessage(Messages::earlyRenewal());
		}
	}
}

void Receptionist::cancelSub(long long memberID)
{
	FileManager::members[memberID].cancelPlan();
}

void Receptionist::renewSub(long long memberID)
{
	FileManager::members[memberID].renewPlan();
}

void Receptionist::addToClass(string className, long long memberId)
{
	FileManager::classes[className].addMember(memberId);
	FileManager::members[memberId].joinClass(className);
}

void Receptionist::removeFromClass(string className, long long memberId)
{
	FileManager::classes[className].removeMember(memberId);
	FileManager::members[memberId].leaveClass(className);
}

void Receptionist::addToWaiting(string className, long long memberId)
{
	if (FileManager::members[memberId].getVipStatus())
		FileManager::vipWaitingList[className].push(memberId);
	else
		FileManager::waitingLists[className].push(memberId);
}

long long Receptionist::getFirstInWaiting(string className)
{
	long long id = 0;
	if (FileManager::vipWaitingList[className].size())
	{
		id = FileManager::vipWaitingList[className].front();
		FileManager::vipWaitingList[className].pop();
	}

	else if (FileManager::waitingLists[className].size())
	{
		id = FileManager::waitingLists[className].front();
		FileManager::waitingLists[className].pop();
	}

	// Send Message
	FileManager::members[id].pushMessage(Messages::addedTo(className));
	return id;
}

void Receptionist::removeMemberFromGym(long long memberId)
{
	FileManager::members.erase(memberId);
}

string Receptionist::getClassName(int id)
{
	auto it = FileManager::classes.begin();
	while (it != FileManager::classes.end())
	{
		if (it->second.getClassId() == id)
			return it->second.getClassName();
		it++;
	}
}

long long Receptionist::getLastMemberId()
{
	return FileManager::members.rbegin()->first;

}

int Receptionist::applyDiscount(int planNumber, double rate)
{
	return PlansData::getPrice(planNumber) - rate * PlansData::getPrice(planNumber);
}
