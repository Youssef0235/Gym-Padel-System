#pragma once
#include<iostream>
#include<set>
#include"Member.h"
using namespace std;

class ClassInfo
{
private:
	long long classId, coachId;
	string classDay, classTime, className;
	int classCapacity;
	set<Member>classMembers;
public:
	ClassInfo();
	ClassInfo(string ClassDay, string ClassTime, string ClassName, int ClassCapacity, set<Member>ClassMembers, long long ClassId, long long CoachId);
	void setClassId(long long ClassId);
	void setClassTime(string ClassTime);
	void setClassDay(string ClassDay);
	void setCoachId(long long CoachId);
	void setClassCapacity(int Capacity);
	void setClassMembers(set<Member>ClassMembers);
	void setClassName(string ClassName);

	long long getClassId() const;
	string getClassTime() const;
	string getClassDay() const;
	long long getCoachId() const;
	int getClassCapacity() const;
	set<Member>getClassMembers() const;
	string getClassName()const;
	
	void addMember(const Member& member);
	void removeMember(const Member& member);

	// for debug
	void display();
};