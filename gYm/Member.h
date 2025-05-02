#pragma once
#include <iostream>
#include "Person.h"
#include<unordered_set>
#include "Subscription.h"
#include"PlansData.h"
#include<vector>


class Member : public Person
{
private:
    Subscription plan;
    vector<string>pastWorkouts;
    unordered_set<string>subClasses;
    long long ID;
    bool isVip;
    int visits;
public:
    Member();
    Member(string FirstName, string MiddleName, string LastName, int dd, int mm, int yy, long long id, string planName, int dur, vector<string>PastWorkouts, bool vip, int Visits, unordered_set<string>SubClasses);
    Member(string FirstName, string MiddleName, string LastName, int dd, int mm, int yy, long long id, Subscription subscription, vector<string>PastWorkouts, bool vip, int Visits, unordered_set<string>SubClasses);

    void setID(long long id);
    void setVipStatus(bool vip);
    void setVisits(int Visits);
    void setPlan(int PlanNumber);
    void setPlan(const Subscription& sub);
    void setSubClasses(unordered_set<string>SubClasses);

    bool getVipStatus() const;
    long long getID() const;
    vector<string>getPastWorkouts()const;
    string getPlanName() const;
    int getPlanDuration() const;
    int getVisits() const;
    unordered_set<string>getSubClasses() const;

    // For Staff // ---------------------------------------
    Subscription getPlan();
    void joinClass(string className);
    // Handle If In Waiting??
    void leaveClass(string className);
    void addWorkout(string workout);
    void renewPlan();
    void cancelPlan();
    void changePlan(string newPlan);

    // Operator Overloading
    bool operator == (const Member& member);
    bool operator<(const Member& other) const; // For Set
        // for debug
    void display();
};