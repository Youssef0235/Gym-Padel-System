#pragma once
#include"Date.h"

class Person
{
protected:
	string fName, mName, lName;
	Date dateOfBirth;
public:
	Person();
	Person(string firstName, string middleName, string lastName, Date dob);

	string getFname() const;
	string getMname() const;
	string getLname() const;
	Date getDateOfBirth() const;

	void setFname(string Fname);
	void setMname(string Mname);
	void setLname(string Lname);
	void setDay(int Day);
	void setMonth(int Month);
	void setYear(int Year);
};