#include "ClassInfo.h"

ClassInfo::ClassInfo() : classCapacity(0), classId(0), coachId(0)
{
}

ClassInfo::ClassInfo(string ClassDay, string ClassTime, int ClassCapacity, set<Member>ClassMembers, long long ClassId, long long CoachId)
{
	classId = ClassId;
	classDay = ClassDay;
	classTime = ClassTime;
	coachId = CoachId;
	classCapacity = ClassCapacity;
	classMembers = ClassMembers;
}

void ClassInfo::setClassId(long long ClassId)
{
	classId = ClassId;
}

void ClassInfo::setClassTime(string ClassTime)
{
	classTime = ClassTime;
}

void ClassInfo::setClassDay(string ClassDay)
{
	classDay = ClassDay;
}

void ClassInfo::setCoachId(long long CoachId)
{
	coachId = CoachId;
}

void ClassInfo::setClassCapacity(int Capacity)
{
	classCapacity = Capacity;
}

void ClassInfo::setClassMembers(set<Member> ClassMembers)
{
	classMembers = ClassMembers;
}

void ClassInfo::addMember(const Member& member)
{
	classMembers.insert(member);
}

long long ClassInfo::getClassId() const
{
	return classId;
}

string ClassInfo::getClassTime() const
{
	return classTime;
}

string ClassInfo::getClassDay() const
{
	return classDay;
}

long long ClassInfo::getCoachId() const
{
	return coachId;
}

int ClassInfo::getClassCapacity() const
{
	return classCapacity;
}

set<Member> ClassInfo::getClassMembers() const
{
	return classMembers;
}

void ClassInfo::display()
{
	cout << classTime << "\n";
	cout << classDay << "\n";
	cout << classCapacity << "\n";
	cout << coachId << "\n";
}