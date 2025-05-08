#pragma once
#include"Staff.h"
#include"FileManager.h"
#include"Messages.h"

class Receptionist : public Staff
{
public:
	Receptionist();
	Receptionist(string firstName, string middleName, string lastName, Date dob, long long id, int Salary);
	static void sendRenewalNoti();
	static void cancelSub(long long memberID);
	static void renewSub(long long memberID);
	static bool addToClass(string className, long long memberId);
	static void removeFromClass(string className, long long memberId);
	static void addToWaiting(string className, long long memberId);
	static void addFirstInWaiting(string className);
	static void removeMemberFromGym(long long memberId);
	static string getClassName(int id);
	static long long getLastMemberId();
	static int applyDiscount(int planNumber, double rate);
};