#include "PlansData.h"
#include "Subscription.h" 

string PlansData::getName(int number)
{
	if (number == 1)
		return "Basic";
	else if (number == 2)
		return "Standard";
	else if (number == 3)
		return "Premium";
	else if (number == 4)
		return "Ultimate";
}

int PlansData::getDuration(int number)
{
	if (number == 1)
		return 30;
	else if (number == 2)
		return 90;
	else if (number == 3)
		return 180;
	else if (number == 4)
		return 360;
}

int PlansData::getDuration(string planName)
{
	if (planName == "Basic")
		return getDuration(1);
	else if (planName == "Standard")
		return getDuration(2);
	else if (planName == "Premium")
		return getDuration(3);
	else if (planName == "Ultimate")
		return getDuration(4);
}

int PlansData::getPrice(int number)
{
	if (number == 1)
		return 100;
	else if (number == 2)
		return 300;
	else if (number == 3)
		return 600;
	else if (number == 4)
		return 1000;
}

Subscription PlansData::getSubscription(int number)
{
	return Subscription(getName(number), getDuration(number));
}
