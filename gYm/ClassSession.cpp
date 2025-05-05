#include "ClassSession.h"

ClassSession::ClassSession() : classCapacity(0), classId(0), coachId(0)
{
}

// Read Only Info
ClassSession::ClassSession(string ClassDay, string ClassTime, string ClassName, int ClassCapacity, unordered_set<long long>ClassMembers, long long ClassId, long long CoachId)
{
	classId = ClassId;
	classDay = ClassDay;
	classTime = ClassTime;
	coachId = CoachId;
	classCapacity = ClassCapacity;
	classMembers = ClassMembers;
	className = ClassName;
}

void ClassSession::setClassId(long long ClassId)
{
	classId = ClassId;
}

void ClassSession::setClassTime(string ClassTime)
{
	classTime = ClassTime;
}

void ClassSession::setClassDay(string ClassDay)
{
	classDay = ClassDay;
}

void ClassSession::setCoachId(long long CoachId)
{
	coachId = CoachId;
}

void ClassSession::setClassCapacity(int Capacity)
{
	classCapacity = Capacity;
}

void ClassSession::setClassMembers(unordered_set<long long> ClassMembers)
{
	classMembers = ClassMembers;
}

void ClassSession::setClassName(string ClassName)
{
	className = ClassName;
}

long long ClassSession::getClassId() const
{
	return classId;
}

string ClassSession::getClassTime() const
{
	return classTime;
}

string ClassSession::getClassDay() const
{
	return classDay;
}

long long ClassSession::getCoachId() const
{
	return coachId;
}

int ClassSession::getClassCapacity() const
{
	return classCapacity;
}

unordered_set<long long> ClassSession::getClassMembers() const
{
	return classMembers;
}

string ClassSession::getClassName() const
{
	return className;
}

void ClassSession::addMember(long long memberId)
{
	classMembers.insert(memberId);
	classCapacity++;
}

void ClassSession::removeMember(long long memberId)
{
	classMembers.erase(memberId);
	classCapacity--;
}

void ClassSession::clearClassMembers()
{
	classMembers.clear();
	classCapacity = 0;
}

bool ClassSession::hasSpace()
{
	return classMembers.size() <= classCapacity;
}