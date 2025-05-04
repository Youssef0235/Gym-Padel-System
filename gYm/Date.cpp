#include "Date.h"

Date::Date() : day(0), month(0), year(0) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

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

bool Date::isFutureDate(const Date& dateToCheck)
{
    time_t t = time(nullptr);
    tm now;
    localtime_s(&now, &t);
    int currentDay = now.tm_mday;
    int currentMonth = now.tm_mon + 1;
    int currentYear = now.tm_year + 1900;

    if (dateToCheck.getYear() > currentYear)
        return true;
    else if (dateToCheck.getYear() < currentYear)
        return false;
    else // Equal Years
    {
        if (dateToCheck.getMonth() > currentMonth)
            return true;
        else if (dateToCheck.getMonth() < currentMonth)
            return false;
        else
            return dateToCheck.getDay() > currentDay;
    }
}

bool Date::isFirstDay()
{
    time_t t = time(nullptr);
    tm now;
    localtime_s(&now, &t);
    return now.tm_mday == 1;
}

Date Date::extendBy(Date& date, int months)
{
    int yearsToAdd = (date.getMonth() + months) / 12;
    return Date(date.getDay(), (date.getMonth() + months) % 12, date.getYear() + yearsToAdd);
}

bool Date::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

Date Date::getNextDate(const Date& date)
{
    int d = date.day;
    int m = date.month;
    int y = date.year;

    // Days in each month (Feb = 28 for now)
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31 };

    // Handle leap year February
    if (m == 2 && isLeapYear(y))
        daysInMonth[2] = 29;

    d++; // Try next day

    if (d > daysInMonth[m]) 
    {
        d = 1;
        m++;
        if (m > 12) 
        {
            m = 1;
            y++;
        }
    }

    return Date(d, m, y);
}

bool Date::operator == (const Date& date) const
{
	return day == date.day and
		month == date.month and
		year == date.year;
}
