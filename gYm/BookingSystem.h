#pragma once
#include <vector>
#include"FileManager.h"
using namespace std;

// Padel Stuff
class BookingSystem
{
    static bool foundSlot(long long memberId, const Slot& slot);
public:
    static bool isSlotAvailable(const Slot& slot);
    static Slot searchNext(Date date, int slotId, string location);
    static void checkSlotTimePassed();
    static void makeBooking(Slot& slot, long long memberId);
    static bool cancelBooking(long long memberId, Slot slot);
    static void removeSlot(long long memberId, const Slot& slot);
    static long long getCourtId(string location);
};