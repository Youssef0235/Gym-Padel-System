#include "ClassSession.h"

ClassSession::ClassSession() : classCapacity(0), classId(0), coachId(0)
{
}

// Read Only Info
ClassSession::ClassSession(string ClassDay, string ClassTime, string ClassName, int ClassCapacity, unordered_set<long long>ClassMembers, long long ClassId, long long CoachId, int ClassPrice)
{
	classId = ClassId;
	classDay = ClassDay;
	classTime = ClassTime;
	coachId = CoachId;
	classCapacity = ClassCapacity;
	classMembers = ClassMembers;
	className = ClassName;
	classPrice = ClassPrice;
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

void ClassSession::setClassPrice(int price)
{
	classPrice = price;
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

int ClassSession::getClassPrice() const
{
	return classPrice;
}

void ClassSession::addMember(long long memberId)
{
	classMembers.insert(memberId);
}

void ClassSession::removeMember(long long memberId)
{
	classMembers.erase(memberId);
}

void ClassSession::clearClassMembers()
{
	classMembers.clear();
}

bool ClassSession::hasSpace()
{
	return classMembers.size() <= classCapacity;
}