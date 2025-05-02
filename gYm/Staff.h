#pragma once
#include <queue>
#include "chrono"
#include "Person.h"
#include "Member.h"


class Staff : public Person
{
protected:
	long long ID;
public:
	Staff();
	Staff(string firstName, string middleName, string lastName, int dd, int mm, int yy, long long id);

	long long getID() const;

	void setID(long long id);

	void viewMemberInfo(vector<Member>&members);
	void searchMember(vector<Member>& members, long long memID);
	vector<Member> ManageSubscription(vector<Member>&members);
};