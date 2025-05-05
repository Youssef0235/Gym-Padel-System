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
	static void sendAddedToNoti();
	static void cancelSub(long long memberID);
	static void renewSub(long long memberID);
};