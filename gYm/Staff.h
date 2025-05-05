#pragma once
#include <queue>
#include "chrono"
#include "Person.h"
#include "Member.h"


class Staff : public Person
{
protected:
	long long ID;
	int salary;
public:
	Staff();
	Staff(string firstName, string middleName, string lastName, Date dob, long long id, int Salary);

	long long getID() const;
	int getSalary()const;

	void setID(long long id);
	void setSalary(int Salary);
};