#pragma once
#include <iostream>
#include"json.hpp"
using json = nlohmann::json;
using namespace std;

class Court
{
private:
	long long courtId;
	string courtLocation, courtName;
	int bookingPrice;
public:
	Court();
	Court(long long CourtId, string CourtLocation, string CourtName, int BookingPrice);

	void setID(long long CourtId);
	void setLocation(string CourtLocation);
	void setName(string CourtName);
	void setBookingPrice(int price);

	long long getID() const;
	string getLocation() const;
	string getName() const;
	int getBookingPrice() const;
};


inline void from_json(const json& j, Court& u)
{
	u = Court
	{
		j.at("ID").get<long long>(),
		j.at("Location").get<string>(),
		j.at("Name").get<string>(),
		j.at("Booking Price").get<int>()
	};
}

inline void to_json(json& j, const Court& u)
{
	j = json
	{
		{"ID", u.getID()},
		{"Location", u.getLocation()},
		{"Name", u.getName()},
		{"Booking Price", u.getBookingPrice()}
	};
}