#define _CRT_SECURE_NO_WARNINGS
#include "Staff.h"
#include "Member.h"
#include <ctime>
using namespace chrono;


Staff::Staff() : ID(0), salary(0) {}

Staff::Staff(string firstName, string middleName, string lastName, Date dob, long long id, int Salary) : Person(firstName, middleName, lastName, dob)
{
	ID = id;
	salary = Salary;
}


long long Staff::getID() const
{
	return ID;
}

int Staff::getSalary() const
{
	return salary;
}

void Staff::setID(long long id)
{
	ID = id;
}

void Staff::setSalary(int Salary)
{
	salary = Salary;
}

// set
void Staff::viewMemberInfo(vector<Member>& members)
{
	for (Member member : members)
	{
		member.getFname();
		member.getID();
	}
}

// set
void Staff::searchMember(vector<Member>& members, long long memID)
{
	for (Member member : members)
	{
		if (member.getID() == memID)
		{
			member.getFname();
			member.getID();
		}
	}
}

vector<Member> Staff::ManageSubscription(vector<Member>& members)
{

	vector<Member> membersToRenew;

	auto now = system_clock::now();
	auto now_time_t = system_clock::to_time_t(now);
	tm* now_tm = localtime(&now_time_t);

	Date currentDate(now_tm->tm_mday, now_tm->tm_mon + 1, now_tm->tm_year + 1900);

	for (Member& member : members) 
	{

		Date endDate(member.getPlan().getEndDate().getDay(), member.getPlan().getEndDate().getMonth(), member.getPlan().getEndDate().getYear());

		int daysUntilRenewal = (endDate.getYear() - currentDate.getYear()) * 365 +
			(endDate.getMonth() - currentDate.getMonth()) * 30 +
			(endDate.getDay() - currentDate.getDay());

		if (daysUntilRenewal <= 7) 
		{
			membersToRenew.push_back(member);
		}
	}

	return membersToRenew;
}