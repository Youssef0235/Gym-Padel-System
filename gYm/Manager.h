#pragma once
#include"FileManager.h"
#include"Staff.h"

class Manager : public Staff
{
private:
	// Comparator To Sort Based On Visits
	static bool comp(const Member& a, const Member& b); 
public:
	Manager();
	Manager(string firstName, string middleName, string lastName, Date dob, int id, int Salary);
	static int getTotalRevenue();
	static vector<long long> getMostActive();
};