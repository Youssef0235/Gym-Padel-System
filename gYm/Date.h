#pragma once
#include<iostream>
#include <iomanip>
#include <sstream>
#include"json.hpp"
using namespace std;
using json = nlohmann::json;


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
	static bool oneWeekLeft(const Date& a, const Date& b);
	static bool isNow(const string time);

	// Operator Overloading
	bool operator == (const Date& date) const;
};

inline void from_json(const json& j, Date& u)
{
	u = Date
	{
		j.at("Day").get<int>(),
		j.at("Month").get<int>(),
		j.at("Year").get<int>()
	};
}

inline void to_json(json& j, const Date& u)
{
	j = json
	{
		{"Day", u.getDay()},
		{"Month", u.getMonth()},
		{"Year", u.getYear()}
	};
}