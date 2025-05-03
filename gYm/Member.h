#pragma once
#include <iostream>
#include<vector>
#include<unordered_set>
#include "Person.h"
#include "Subscription.h"
#include"PlansData.h"


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
    Member(string FirstName, string MiddleName, string LastName, Date dob, long long id, string planName, vector<string>PastWorkouts, bool vip, int Visits, unordered_set<string>SubClasses, Date endDate);

    void setID(long long id);
    void setVipStatus(bool vip);
    void setVisits(int Visits);
    void setPlan(int PlanNumber);
    void setSubClasses(unordered_set<string>SubClasses);
    void setEndDate();


    bool getVipStatus() const;
    long long getID() const;
    vector<string>getPastWorkouts()const;
    unordered_set<string>getSubClasses() const;
    string getPlanName() const;
    int getVisits() const;
    Date getEndDate() const;


    // For Staff // ---------------------------------------
    Subscription getPlan();
    void joinClass(string className);
    // Handle If In Waiting??
    void leaveClass(string className);
    void addWorkout(string workout);
    // when sub ends
    void resetSubscription();
    void renewPlan();
    void cancelPlan();
    void changePlan(string newPlan);

    // Operator Overloading
    bool operator == (const Member& member);
    bool operator<(const Member& other) const; // For Set
        // for debug
    void display();
};