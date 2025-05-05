#pragma once
#include <iostream>
#include<vector>
#include<unordered_set>
#include<set>
#include "Person.h"
#include "Subscription.h"
#include"PlansData.h"
#include"Slot.h"


class Member : public Person
{
private:
    Subscription plan;
    vector<string>pastWorkouts;
    unordered_set<string>subClasses;
    // Check Ds
    vector<Slot>slots;
    long long ID;
    bool isVip;
    int visits, totalPaid;
public:
    Member();
    Member(string FirstName, string MiddleName, string LastName, Date dob, long long id, string planName, vector<string>PastWorkouts, bool vip, int Visits, unordered_set<string>SubClasses, Date endDate, int TotalPaid, vector<Slot> Slots);

    void setID(long long id);
    void setVipStatus(bool vip);
    void setVisits(int Visits);
    void setPlan(int PlanNumber);
    void setSubClasses(unordered_set<string>SubClasses);
    void setTotalPaid(int TotalPaid);
    void setSlots(vector<Slot>Slots);

    bool getVipStatus() const;
    long long getID() const;
    vector<string>getPastWorkouts() const;
    unordered_set<string>getSubClasses() const;
    string getPlanName() const;
    int getVisits() const;
    int getTotalPaid() const;
    Date getEndDate() const;
    vector<Slot>getSlots() const;


    // For Staff
    Subscription getPlan();
    void joinClass(string className);
    void leaveClass(string className);
    void addWorkout(string workout);
    void removeSlot(const Slot& slot);
    void addSlot(const Slot& slot);
    void renewPlan();
    void cancelPlan();
    void changePlan(string newPlan);

    // Operator Overloading
    bool operator == (const Member& member);

    // for debug
    void display();
};