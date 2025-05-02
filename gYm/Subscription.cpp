#include "Subscription.h"
#include "PlansData.h"

Subscription::Subscription() : duration(0)
{
}

Subscription::Subscription(string Name, int Duration) : name(Name), duration(Duration)
{
}

void Subscription::setPlanName(string Name)
{
	name = Name;
}

void Subscription::setPlanDuration(int Duration)
{
	duration = Duration;
}

void Subscription::setPlan(const Subscription& subscription)
{
	name = subscription.name;
	duration = subscription.duration;
}

void Subscription::setStartDate(const Date& StartDate)
{
	startDate = StartDate;
}

void Subscription::setEndDate(const Date& EndDate)
{
	endDate = EndDate;
}

// CHECK!
void Subscription::setEndDate()
{
	endDate.setDay(startDate.getDay());
	endDate.setMonth((startDate.getMonth() + (duration / 30)) % 12);
	endDate.setYear(startDate.getYear() + (startDate.getMonth() == 12 ? 1 : 0));
}

string Subscription::getName() const
{
	return name;
}

int Subscription::getDuration() const
{
	return duration;
}

int Subscription::getEndDay() const
{
	return endDate.getDay();
}

int Subscription::getEndMonth() const
{
	return endDate.getMonth();
}

int Subscription::getEndYear() const
{
	return endDate.getYear();
}

Date Subscription::getStartDate() const
{
	return startDate;
}

Date Subscription::getEndDate() const
{
	return endDate;
}

void Subscription::extendPlan(string planName)
{
	duration += PlansData::getDuration(planName);
}

void Subscription::cancelPlan()
{
	duration = 0;
	name = "";
}

void Subscription::changePlan(string newPlan)
{
	duration = PlansData::getDuration(newPlan);
	name = newPlan;
}

bool Subscription::operator==(const Subscription& subscription) const
{
	return name == subscription.name and
		duration == subscription.duration;
}