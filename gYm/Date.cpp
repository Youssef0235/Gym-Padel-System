#include "Date.h"

Date::Date() : day(0), month(0), year(0)
{
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y)
{
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

void Date::setDay(int Day)
{
	day = Day;
}

void Date::setMonth(int Month)
{
	month = Month;
}

void Date::setYear(int Year)
{
	year = Year;
}

Date Date::getTodaysDate()
{
	time_t t = time(nullptr);
	tm now;
	localtime_s(&now, &t);
	int currentDay = now.tm_mday;
	int currentMonth = now.tm_mon + 1; 
	int currentYear = now.tm_year + 1900;
	return Date(currentDay, currentMonth, currentYear);
}

bool Date::operator == (const Date& date) const
{
	return day == date.day and
		month == date.month and
		year == date.year;
}
