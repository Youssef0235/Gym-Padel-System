#include "Subscription.h"

Subscription::Subscription() {}

Subscription::Subscription(string Name, const Date& EndDate) : name(Name)
{
	endDate = EndDate;
}

void Subscription::setPlanName(string Name)
{
	name = Name;
}

void Subscription::setPlan(const Subscription& subscription)
{
	name = subscription.name;
	endDate = subscription.endDate;
}

void Subscription::setEndDate()
{
	endDate.setDay(Date::getTodaysDate().getDay());
	endDate.setMonth((Date::getTodaysDate().getMonth() + (PlansData::getDuration(name) / 30)) % 12);
	endDate.setYear(Date::getTodaysDate().getYear() + Date::getTodaysDate().getMonth() / 12);
}

string Subscription::getName() const
{
	return name;
}

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
}

// only when sub ends
void Subscription::changePlan(string newPlan)
{
	name = newPlan;
	setEndDate();
}

bool Subscription::operator==(const Subscription& subscription) const
{
	return name == subscription.name and
		endDate == subscription.endDate;
}