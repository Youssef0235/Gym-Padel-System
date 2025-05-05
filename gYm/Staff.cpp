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