#pragma once
#include"Staff.h"

class Manager : public Staff
{
private:

public:
	Manager();
	Manager(string firstName, string middleName, string lastName, Date dob, int id, int Salary);
	string getRole() const override;
};