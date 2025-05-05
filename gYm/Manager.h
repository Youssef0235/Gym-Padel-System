#pragma once
#include"FileManager.h"
#include"Staff.h"

class Manager : public Staff
{
private:
	static bool comp(const Member& a, const Member& b); // Comparator
public:
	Manager();
	Manager(string firstName, string middleName, string lastName, Date dob, int id, int Salary);
	static int getTotalRevenue();
	static vector<long long> getMostActive();
};