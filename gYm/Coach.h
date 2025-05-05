#pragma once
#include <vector>
#include "Staff.h"
#include "ClassSession.h"

class Coach : public Staff
{
private:
    vector<ClassSession> assignedClasses;
    string className;
public:
    Coach();
    Coach(string firstName, string middleName, string lastName, string ClassName, Date dob, long long id, vector<ClassSession>AssignedClasses, int Salary);

    void setClassName(string ClassName);

    string getClassName() const;

    void assignClass(const ClassSession& classSession);
    void removeClass(long long classId);
    vector<ClassSession> getAssignedClasses() const;
    void clearAssignedClasses();
};

inline void from_json(const json& j, Coach& u)
{
	u = Coach
	{
		j.at("First Name").get<string>(),
		j.at("Middle Name").get<string>(),
		j.at("Last Name").get<string>(),
		j.at("Class").get<string>(),
		j.at("Birth Date").get<Date>(),
		j.at("ID").get<long long>(),
		j.at("Assigned Classes").get<vector<ClassSession>>(),
		j.at("Salary").get<int>()
	};
}

inline void to_json(json& j, const Coach& u)
{
	j = json
	{
		{"First Name", u.getFname()},
		{"Middle Name", u.getMname()},
		{"Last Name", u.getLname()},
		{"Class", u.getClassName()},
		{"Birth Date", u.getDateOfBirth()},
		{"ID", u.getID()},
		{"Assigned Classes", u.getAssignedClasses()},
		{"Salary", u.getSalary()}
	};
}