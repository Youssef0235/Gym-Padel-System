#include "Person.h"

Person::Person()
{
}

Person::Person(string firstName, string middleName, string lastName, int dd, int mm, int yy) : dateOfBirth(dd, mm, yy)
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

int Person::getDay() const
{
	return dateOfBirth.getDay();
}

int Person::getMonth() const
{
	return dateOfBirth.getMonth();
}

int Person::getYear() const
{
	return dateOfBirth.getYear();
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
