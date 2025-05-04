#pragma once
#include<iostream>
#include "Date.h"
#include"PlansData.h"
using namespace std;


// Basic, Standard, Premium, Ultimate 
class Subscription
{
private:
	string name;
	Date endDate;
public:
	Subscription();
	Subscription(string Name, const Date& EndDate);

	void setPlanName(string Name);
	void setPlan(const Subscription& subscription);
	void setEndDate();

	string getName() const;
	Date getEndDate() const;

	void extendPlan(string planName);
	void cancelPlan();
	void changePlan(string newPlan);

	// Opertor Overloading
	bool operator == (const Subscription& subscription) const;
};