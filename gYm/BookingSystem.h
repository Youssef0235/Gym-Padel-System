#pragma once
#include <vector>
#include "Court.h"
#include "Slot.h"
using namespace std;

class BookingSystem
{
private:
    vector<Court> courts;
    vector<Slot> slots;

public:

    void addCourt(int cid, string loc);
    Slot searchAvailableCourts(Date date, int sid, string loc);
    void checkSlotTimePassed(vector<Slot>& slots);
    void makeBooking(Slot s, int mID);
    bool cancelBooking(int sid);

};