#pragma once
#include<iostream>
#include "Date.h"


using namespace std;

// Basic, Standard, Premium, Ultimate 
class Subscription
{
private:
	string name;
	int duration;

	//For Staff
	Date startTime;
	Date endTime;
public:
	Subscription();
	Subscription(string Name, int Duration);
	void setName(string Name);
	void setDurtion(int Duration);
	void setPlan(const Subscription& subscription);

	//For Staff
	void setStartTime(int day, int month, int year);
	void setEndTime();

	string getName() const;
	int getDuration() const;

	//For Staff
	int getEndDay();
	int getEndMonth();
	int getEndYear();

	void extendPlan(string planName);
	void cancelPlan();
	void changePlan(string newPlan);

	// Opertor Overloading
	bool operator == (const Subscription& subscription) const;
};