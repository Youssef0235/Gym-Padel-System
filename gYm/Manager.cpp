#include "Manager.h"

Manager::Manager() {}

Manager::Manager(string firstName, string middleName, string lastName, Date dob, int id, int Salary) : Staff(firstName, middleName, lastName, dob, id, Salary) 
{}

bool Manager::comp(const Member& a, const Member& b)
{
	return a.getVisits() > b.getVisits();
}

int Manager::getTotalRevenue()
{
	int totalPaidByGym = 0, totalPaidToGym = 0;
	auto coachesIt = FileManager::coachesInfo.begin();
	while (coachesIt != FileManager::coachesInfo.end())
	{
		totalPaidByGym += FileManager::coachesInfo[coachesIt->first].getSalary();
		coachesIt++;
	}
	auto membersIt = FileManager::members.begin();
	while (membersIt != FileManager::members.end())
	{
		totalPaidToGym += FileManager::members[membersIt->first].getTotalPaid();
		membersIt++;
	}
	return totalPaidToGym - totalPaidByGym;
}

vector<long long> Manager::getMostActive()
{
	vector<Member>myMembers;
	auto it = FileManager::members.begin();
	while (it != FileManager::members.end())
	{
		myMembers.push_back(it->second);
		it++;
	}
	sort(myMembers.begin(), myMembers.end(), comp);
	vector<long long>membersId(5);
	for (int i = 0; i < 5; i++)
		membersId[i] = myMembers[i].getID();
	return membersId;
}
