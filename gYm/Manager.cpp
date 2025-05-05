#include "Manager.h"

Manager::Manager() {}

Manager::Manager(string firstName, string middleName, string lastName, Date dob, int id, int Salary) : Staff(firstName, middleName, lastName, dob, id, Salary) 
{}

string Manager::getRole() const
{
	return "Manager";
}
