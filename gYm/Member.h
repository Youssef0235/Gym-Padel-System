#pragma once
#include <iostream>
#include "Person.h"
#include "Subscription.h"
#include"PlansData.h"
#include<vector>


class Member : public Person
{
private:
    Subscription plan;
    vector<string>pastWorkouts;
    long long ID;
    bool isVip;

public:
    Member();
    Member(string FirstName, string MiddleName, string LastName, int dd, int mm, int yy, long long id, string planName, int dur, vector<string>PastWorkouts, bool vip);
    void setID(long long id);
    void setVipStatus(bool vip);
    bool getVipStatus() const;
    long long getID() const;
    vector<string>getPastWorkouts()const;
    string getPlanName() const;
    int getPlanDuration() const;
    //For Staff
    Subscription getPlan();
    void addWorkout(string workout);
    void renew(string planName);
    void cancel();
    void change(string newPlan);
    // Operator Overloading
    bool operator == (const Member& member);
    bool operator<(const Member& other) const; // For Set
        // for debug
    void display();
};