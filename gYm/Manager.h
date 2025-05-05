#pragma once
#include"Staff.h"

class Manager : public Staff
{
private:

public:
	Manager();
	Manager(string firstName, string middleName, string lastName, Date dob, long long id, int Salary);
};