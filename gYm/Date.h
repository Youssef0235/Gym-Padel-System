#pragma once
#include<iostream>
using namespace std;


class Date
{
private:
	int day, month, year;
public:
	Date();
	Date(int d, int m, int y);

	int getDay() const;
	int getMonth() const;
	int getYear() const;
	static Date getTodaysDate();

	void setDay(int Day);
	void setMonth(int Month);
	void setYear(int Year);


	// Operator Overloading
	bool operator == (const Date& date) const;
};