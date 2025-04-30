#include "PlansData.h"

int PlansData::getDuration(string planName)
{
	if (planName == "Basic")
		return 30;
	if (planName == "Standard")
		return 90;
	if (planName == "Premium")
		return 180;
	if (planName == "Ultimte")
		return 360;
	return 0;
}

int PlansData::getPrice(string planName)
{
	if (planName == "Basic")
		return 100;
	if (planName == "Standard")
		return 300;
	if (planName == "Premium")
		return 600;
	if (planName == "Ultimte")
		return 1000;
	return 0;
}
