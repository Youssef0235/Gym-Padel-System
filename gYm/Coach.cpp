#include "Coach.h"

Coach::Coach() {}

Coach::Coach(string firstName, string middleName, string lastName, string ClassName, Date dob, long long id, vector<ClassSession> AssignedClasses, int Salary) : Staff(firstName, middleName, lastName, dob, id, Salary)
{
	className = ClassName;
	assignedClasses = AssignedClasses;
}

void Coach::setClassName(string ClassName)
{
	className = ClassName;
}

string Coach::getClassName() const
{
	return className;
}

string Coach::getRole() const
{
	return "Coach";
}


void Coach::assignClass(const ClassSession& classSession)
{
	assignedClasses.push_back(classSession);
}

void Coach::removeClass(long long classId)
{
	auto it = assignedClasses.begin();
	while(it != assignedClasses.end())
	{
		if (it->getClassId() == classId)
		{
			assignedClasses.erase(it);
			return;
		}
		it++;
	}
}

vector<ClassSession> Coach::getAssignedClasses() const
{
	return assignedClasses;
}

void Coach::clearAssignedClasses()
{
	assignedClasses.clear();
}