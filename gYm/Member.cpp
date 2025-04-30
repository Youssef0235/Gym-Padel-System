#include "Member.h"
using namespace std;

Member::Member() : ID(0), isVip(0) {}

Member::Member(string FirstName, string MiddleName, string LastName, int dd, int mm, int yy, long long id, string planName, int dur, vector<string>PastWorkouts, bool vip) : Person(FirstName, MiddleName, LastName, dd, mm, yy), plan(planName, dur)
{
    ID = id;
    pastWorkouts = PastWorkouts;
    isVip = vip;
}

void Member::setID(long long id)
{
    ID = id;
}

void Member::setVipStatus(bool vip)
{
    isVip = vip;
}

bool Member::getVipStatus() const
{
    return isVip;
}

void Member::addWorkout(string workout)
{
    pastWorkouts.push_back(workout);
}

long long Member::getID() const
{
    return ID;
}

vector<string> Member::getPastWorkouts() const
{
    return pastWorkouts;
}

string Member::getPlanName() const
{
    return plan.getName();
}

int Member::getPlanDuration() const
{
    return plan.getDuration();
}

//For Staff
Subscription Member::getPlan()
{
    return plan;
}

// Membership functions

void Member::renew(string planName)
{
    plan.extendPlan(plan.getName());
}

void Member::cancel() {
    plan.cancelPlan();
}

void Member::change(string newPlan) {
    plan.changePlan(newPlan);
}

bool Member::operator==(const Member& member)
{
    return fName == member.fName and
        mName == member.mName and
        lName == member.lName and
        dateOfBirth == member.dateOfBirth and
        ID == member.ID and
        pastWorkouts == member.pastWorkouts and
        plan == member.plan and
        isVip == member.isVip;
}

bool Member::operator<(const Member& other) const
{
    return ID < other.ID;
}

void Member::display()
{
    cout << fName << "\n";
    cout << mName << "\n";
    cout << lName << "\n";
    cout << dateOfBirth.getDay() << "\n";
    cout << dateOfBirth.getMonth() << "\n";
    cout << dateOfBirth.getYear() << "\n";
    cout << ID << "\n";
    cout << plan.getName() << "\n";
    cout << plan.getDuration() << "\n";
    cout << isVip << "\n";
}
