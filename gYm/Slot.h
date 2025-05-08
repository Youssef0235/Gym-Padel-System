#pragma once
#include "Date.h"

// every slot = 1 hour from 0 - 23
class Slot
{
	long long courtID;
	int hour;
	Date date;
public:
	Slot();
	Slot(long long CourtId, int hour, Date Date);

	void setCourtID(long long CourtId);
	void setHour(int hour);
	void setDate(const Date& Date);

	long long getCourtID() const;
	int getHour() const;
	Date getDate() const;

	// Operator Overloading
	bool operator == (const Slot& slot) const;
	bool operator < (const Slot & slot) const;
};

inline void from_json(const json& j, Slot& u)
{
	u = Slot
	{
		j.at("Court ID").get<long long>(),
		j.at("Hour").get<int>(),
		j.at("Date").get<Date>()
	};
}

inline void to_json(json& j, const Slot& u)
{
	j = json
	{
		{"Court ID", u.getCourtID()},
		{"Hour", u.getHour()},
		{"Date", u.getDate()}
	};
}