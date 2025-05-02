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
	Date startDate, endDate;
public:
	Subscription();
	Subscription(string Name, int Duration);
	void setPlanName(string Name);
	void setPlanDuration(int Duration);
	void setPlan(const Subscription& subscription);
	void setStartDate(const Date& StartDate);
	void setEndDate(const Date& EndDate);
	void setEndDate();

	string getName() const;
	int getDuration() const;
	int getEndDay() const;
	int getEndMonth() const;
	int getEndYear() const;
	Date getStartDate() const;
	Date getEndDate() const;


	void extendPlan(string planName);
	void cancelPlan();
	void changePlan(string newPlan);

	// Opertor Overloading
	bool operator == (const Subscription& subscription) const;
};