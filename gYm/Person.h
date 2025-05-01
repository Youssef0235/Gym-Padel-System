#pragma once
#include"Date.h"

class Person
{
protected:
	string fName, mName, lName;
	Date dateOfBirth;
public:
	Person();
	Person(string firstName, string middleName, string lastName, int dd, int mm, int yy);

	string getFname() const;
	string getMname() const;
	string getLname() const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	Date getDateOfBirth() const;

	void setFname(string Fname);
	void setMname(string Mname);
	void setLname(string Lname);
	void setDay(int Day);
	void setMonth(int Month);
	void setYear(int Year);
};