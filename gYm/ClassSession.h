#pragma once
#include<iostream>
#include<set>
#include"Member.h"
using namespace std;

class ClassSession
{
private:
	long long classId, coachId;
	string classDay, classTime, className;
	int classCapacity;
	unordered_set<long long>classMembers;
public:
	ClassSession();
	ClassSession(string ClassDay, string ClassTime, string ClassName, int ClassCapacity, unordered_set<long long>ClassMembers, long long ClassId, long long CoachId);

	void setClassId(long long ClassId);
	void setClassTime(string ClassTime);
	void setClassDay(string ClassDay);
	void setCoachId(long long CoachId);
	void setClassCapacity(int Capacity);
	void setClassMembers(unordered_set<long long>ClassMembers);
	void setClassName(string ClassName);

	long long getClassId() const;
	string getClassTime() const;
	string getClassDay() const;
	long long getCoachId() const;
	int getClassCapacity() const;
	unordered_set<long long>getClassMembers() const;
	string getClassName()const;
	
	void addMember(long long memberId);
	void removeMember(long long memberId);
	void clearClassMembers();
	bool hasSpace();
};