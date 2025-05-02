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
	Date endDate;
public:
	Subscription();
	Subscription(string Name, int Duration);
	void setPlanName(string Name);
	void setPlanDuration(int Duration);
	void setPlan(const Subscription& subscription);
	void setEndDate();

	string getName() const;
	int getDuration() const;
	Date getEndDate() const;


	void extendPlan(string planName);
	void cancelPlan();
	void changePlan(string newPlan);

	// Opertor Overloading
	bool operator == (const Subscription& subscription) const;
};