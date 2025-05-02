#include "Subscription.h"
#include "PlansData.h"

Subscription::Subscription() : duration(0)
{
}

Subscription::Subscription(string Name, int Duration) : name(Name), duration(Duration)
{
}

void Subscription::setName(string Name)
{
	name = Name;
}

void Subscription::setDurtion(int Duration)
{
	duration = Duration;
}

void Subscription::setPlan(const Subscription& subscription)
{
	name = subscription.name;
	duration = subscription.duration;
}

//For Staff
void Subscription::setStartTime(int day, int month, int year)
{

	startTime.setDay(day);
	startTime.setMonth(month);
	startTime.setYear(day);
}

// CHECK!
void Subscription::setEndTime()
{

	endTime.setDay(startTime.getDay());
	endTime.setMonth((startTime.getMonth() + duration) % 12);
	endTime.setYear(startTime.getYear() + ((startTime.getMonth() + endTime.getMonth()) / 12));
}

string Subscription::getName() const
{
	return name;
}

int Subscription::getDuration() const
{
	return duration;
}

// For Staff
int Subscription::getEndDay()
{
	return endTime.getDay();
}

int Subscription::getEndMonth()
{
	return endTime.getMonth();
}

int Subscription::getEndYear()
{
	return endTime.getYear();
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