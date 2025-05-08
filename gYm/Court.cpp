#include "Court.h"

Court::Court() : courtId(0) {}

Court::Court(long long CourtId, string CourtLocation, string CourtName, int BookingPrice)
{
	courtId = CourtId;
	courtLocation = CourtLocation;
	courtName = CourtName;
	bookingPrice = BookingPrice;
}

void Court::setID(long long Courtid)
{
	courtId = Courtid;
}

void Court::setLocation(string CourtLocation)
{
	courtLocation = CourtLocation;
}

void Court::setName(string CourtName)
{
	courtName = CourtName;
}

void Court::setBookingPrice(int price)
{
	bookingPrice = price;
}

long long Court::getID() const
{
	return courtId;
}

string Court::getLocation() const
{
	return courtLocation;
}

string Court::getName() const
{
	return courtName;
}

int Court::getBookingPrice() const
{
	return bookingPrice;
}
