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

	void setDay(int Day);
	void setMonth(int Month);
	void setYear(int Year);

	// Utilities
	static Date getTodaysDate();
	static bool isFutureDate(const Date& dateToCheck);
	static bool isFirstDay();
	static Date extendBy(Date&date, int months);
	static bool isLeapYear(int year);
	static Date getNextDate(const Date& date);

	// Operator Overloading
	bool operator == (const Date& date) const;
};