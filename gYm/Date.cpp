#include "Date.h"

Date::Date() : day(0), month(0), year(0) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

int Date::daysInMonth(int mm, int yy)
{
    switch (mm)
    {
    case 2: return isLeapYear(yy) ? 29 : 28;
    case 4: case 6: case 9: case 11: return 30;
    default: return 31;
    }
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

bool Date::isFutureDate(const Date& dateToCheck)
{
    time_t t = time(nullptr);
    tm now;
    localtime_s(&now, &t);
    int currentDay = now.tm_mday;
    int currentMonth = now.tm_mon + 1;
    int currentYear = now.tm_year + 1900;
    if (dateToCheck.getYear() != currentYear)
        return dateToCheck.getYear() > currentYear;
    else  if (dateToCheck.getMonth() != currentMonth)
        return dateToCheck.getMonth() > currentMonth;
    else // If dateToCheck.getDay() == currentDay -> todays date -> Not Future
        return dateToCheck.getDay() > currentDay;
}

bool Date::isFirstDay()
{
    time_t t = time(nullptr);
    tm now;
    localtime_s(&now, &t);
    return now.tm_mday == 1;
}

Date Date::extendBy(Date date, int months)
{
    int mm = months + date.getMonth();
    int yy = date.getYear() + (mm - 1) / 12;
    mm = (mm - 1) % 12 + 1;
    int maxDay = daysInMonth(mm, yy);
    int dd = min(date.getDay(), maxDay);
    return Date(date.getDay(), mm, yy);
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
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31 };

    if (m == 2 && isLeapYear(y))
        daysInMonth[2] = 29;
    d++; 
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

bool Date::oneWeekLeft(const Date& a, const Date& b)
{
    tm date1 = {};
    date1.tm_year = a.getYear() - 1900;
    date1.tm_mon = a.getMonth() - 1;
    date1.tm_mday = a.getDay();

    tm date2 = {};
    date2.tm_year = b.getYear() - 1900; 
    date2.tm_mon = b.getMonth() - 1;     
    date2.tm_mday = b.getDay();        

    time_t time1 = std::mktime(&date1);
    time_t time2 = std::mktime(&date2);
    double diff = difftime(time2, time1);
    return diff == 7 * 24 * 60 * 60;
}

bool Date::isNow(const string givenTime)
{
    time_t t = time(nullptr);
    tm current_time = {};
    localtime_s(&current_time, &t);
    ostringstream oss;
    oss << put_time(&current_time, "%H:%M:%S");
    string current_time_str = oss.str();
    return current_time_str > givenTime;
}

bool Date::operator == (const Date& date) const
{
	return day == date.day and
		month == date.month and
		year == date.year;
}

bool Date::operator!=(const Date& date) const
{
    return day != date.day or
        month != date.month or
        year != date.year;
}

bool Date::operator<(const Date& date) const
{
    if (year != date.getYear())
        return year < date.getYear();
    if (month != date.getMonth())
        return year < date.getMonth();
    return day < date.getDay();
}
