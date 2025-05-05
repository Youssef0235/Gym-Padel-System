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

void Receptionist::sendAddedToNoti()
{

}

void Receptionist::cancelSub(long long memberID)
{
	FileManager::members[memberID].cancelPlan();
}

void Receptionist::renewSub(long long memberID)
{
	FileManager::members[memberID].renewPlan();
}