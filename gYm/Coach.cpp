#include "Coach.h"

Coach::Coach()
{
	ID = 0;
	role = "Coach";
}

Coach::Coach(string firstName, string middleName, string lastName, string ClassName, int dd, int mm, int yy, long long id, vector<ClassInfo> AssignedClasses) : Staff(firstName, middleName, lastName, dd, mm, yy, id)
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


void Coach::assignClass(const ClassInfo& classInfo)
{
	assignedClasses.push_back(classInfo);
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

vector<ClassInfo> Coach::getAssignedClasses() const
{
	return assignedClasses;
}