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
public:
	Court();
	Court(long long CourtId, string CourtLocation, string CourtName);

	void setID(long long CourtId);
	void setLocation(string CourtLocation);
	void setName(string CourtName);

	long long getID() const;
	string getLocation() const;
	string getName() const;
};


inline void from_json(const json& j, Court& u)
{
	u = Court
	{
		j.at("ID").get<long long>(),
		j.at("Location").get<string>(),
		j.at("Name").get<string>()
	};
}

inline void to_json(json& j, const Court& u)
{
	j = json
	{
		{"ID", u.getID()},
		{"Location", u.getLocation()},
		{"Name", u.getName()},
	};
}
