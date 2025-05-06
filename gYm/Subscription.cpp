#include "Subscription.h"

Subscription::Subscription() {}

// OK
Subscription::Subscription(string Name, const Date& EndDate)
{
	name = Name;
	endDate = EndDate;
}

// OK
void Subscription::setPlanName(string Name)
{
	name = Name;
}

// OK
void Subscription::setPlan(const Subscription& subscription)
{
	name = subscription.name;
	endDate = subscription.endDate;
}

void Subscription::setEndDate(const Date& EndDate)
{
	endDate = EndDate;
}

// Todays Date + Sub
void Subscription::calcEndDate()
{
	endDate = Date::extendBy(Date::getTodaysDate(), PlansData::getDuration(name) / 30);
}

// OK
string Subscription::getName() const
{
	return name;
}

// OK
Date Subscription::getEndDate() const
{
	return endDate;
}

void Subscription::extendPlan(string planName)
{
	endDate = Date::extendBy(endDate, PlansData::getDuration(planName) / 30);
}

void Subscription::cancelPlan()
{
	name = "";
	endDate = Date::getTodaysDate();
}

void Subscription::changePlan(string newPlan)
{
	cancelPlan();
	name = newPlan;
	calcEndDate();
}

// OK
bool Subscription::operator==(const Subscription& subscription) const
{
	return name == subscription.name and
		endDate == subscription.endDate;
}