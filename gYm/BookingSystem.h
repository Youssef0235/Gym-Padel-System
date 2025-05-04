#pragma once
#include <vector>
#include"FileManager.h"
using namespace std;

class BookingSystem
{
public:
    static bool isSlotAvailable(const Slot& slot);
    static Slot searchAvailableCourts(Date date, int sid, string loc);
    static void checkSlotTimePassed();
    static void makeBooking(Slot& slot, long long memberId);
    static bool cancelBooking(long long memberId, Slot slot);

};