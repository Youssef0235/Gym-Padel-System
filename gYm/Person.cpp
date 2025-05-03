#include "Person.h"

Person::Person()
{
}

Person::Person(string firstName, string middleName, string lastName, Date dob) : dateOfBirth(dob)
{
	fName = firstName;
	mName = middleName;
	lName = lastName;
}

string Person::getFname() const
{
	return fName;
}

string Person::getMname() const
{
	return mName;
}

string Person::getLname() const
{
	return lName;
}

void Person::setFname(string Fname)
{
	fName = Fname;
}

void Person::setMname(string Mname)
{
	mName = Mname;
}

void Person::setLname(string Lname)
{
	lName = Lname;
}

Date Person::getDateOfBirth() const
{
	return dateOfBirth;
}

void Person::setDay(int Day)
{
	dateOfBirth.setDay(Day);
}

void Person::setMonth(int Month)
{
	dateOfBirth.setMonth(Month);
}

void Person::setYear(int Year)
{
	dateOfBirth.setYear(Year);
}
