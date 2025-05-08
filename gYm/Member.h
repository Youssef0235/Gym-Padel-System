#pragma once
#include <iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<stack>
#include<deque>
#include "Person.h"
#include "Subscription.h"
#include"PlansData.h"
#include"Slot.h"

class Member : public Person
{
private:
    Subscription plan;
    deque<string>pastWorkouts;
    unordered_set<string>subClasses;
    set<Slot>slots;
    vector<string>inbox;
    long long ID;
    bool isVip;
    int visits, totalPaid;
public:
    Member();
    Member(string FirstName, string MiddleName, string LastName, Date dob, long long id, string planName, deque<string>PastWorkouts, bool vip, int Visits, unordered_set<string>SubClasses, Date endDate, int TotalPaid, set<Slot> Slots, vector<string>Inbox);

    void setID(long long id);
    void setVipStatus(bool vip);
    void setVisits(int Visits);
    void setPlan(int PlanNumber);
    void setSubClasses(unordered_set<string>SubClasses);
    void setTotalPaid(int TotalPaid);
    void setSlots(set<Slot>Slots);
    void setInbox(vector<string>Inbox);

    bool getVipStatus() const;
    long long getID() const;
    deque<string>getPastWorkouts() const;
    unordered_set<string>getSubClasses() const;
    string getPlanName() const;
    int getVisits() const;
    int getTotalPaid() const;
    Date getEndDate() const;
    set<Slot>getSlots() const;
    vector<string>getInbox() const;
    

    // For Staff
    Subscription getPlan();
    void joinClass(string className);
    void leaveClass(string className);
    void addWorkout(string workout);
    void removeSlot(const Slot& slot);
    bool inClass(string className);
    void addSlot(const Slot& slot);
    void pushMessage(string Message);
    void clearInbox();
    void renewPlan();
    void cancelPlan();
    void changePlan(string newPlan);

    // Operator Overloading
    bool operator == (const Member& member);

    // for debug
    void display();
};


inline void from_json(const json& j, Member& u)
{
    u = Member
    {
        j.at("First Name").get<string>(),
        j.at("Middle Name").get<string>(),
        j.at("Last Name").get<string>(),
        j.at("Birth Date").get<Date>(),
        j.at("ID").get<long long>(),
        j.at("Plan").get<string>(),
        j.at("Past Workouts").get<deque<string>>(),
        j.at("VIP").get<bool>(),
        j.at("Visits").get<int>(),
        j.at("Classes").get<unordered_set<string>>(),
        j.at("End Date").get<Date>(),
        j.at("Total Paid").get<int>(),
        j.at("Slots").get<set<Slot>>(),
        j.at("Inbox").get<vector<string>>()
    };
}   

inline void to_json(json& j, const Member& u)
{
    j = json
    {
        {"First Name", u.getFname()},
        {"Middle Name", u.getMname()},
        {"Last Name", u.getLname()},
        {"Birth Date", u.getDateOfBirth()},
        {"ID", u.getID()},
        {"Plan", u.getPlanName()},
        {"Past Workouts", u.getPastWorkouts()},
        {"VIP", u.getVipStatus()},
        {"Visits", u.getVisits()},
        {"Classes", u.getSubClasses()},
        {"End Date", u.getEndDate()},
        {"Total Paid", u.getTotalPaid()},
        {"Slots", u.getSlots()},
        {"Inbox", u.getInbox()}
    };
}