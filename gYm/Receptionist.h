#pragma once
#include"Staff.h"

class Receptionist : public Staff
{
private:
public:
	Receptionist();
	Receptionist(string firstName, string middleName, string lastName, Date dob, long long id, int Salary);
	string getRole() const override;
};