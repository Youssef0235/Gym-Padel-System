#include "Member.h"
using namespace std;

Member::Member() : ID(0), isVip(0), visits(0) {}

Member::Member(string FirstName, string MiddleName, string LastName, Date dob, long long id, string planName, vector<string> PastWorkouts, bool vip, int Visits, unordered_set<string> SubClasses, Date endDate) : Person(FirstName, MiddleName, LastName, dob.getDay(), dob.getMonth(), dob.getYear())
{
    ID = id;
    pastWorkouts = PastWorkouts;
    isVip = vip;
    visits = Visits;
    subClasses = SubClasses;
    plan.setPlanName(planName);
    plan.setEndDate();
}

Member::Member(string FirstName, string MiddleName, string LastName, int dd, int mm, int yy, long long id, Subscription subscription, vector<string> PastWorkouts, bool vip, int Visits, unordered_set<string> SubClasses) : Person(FirstName, MiddleName, LastName, dd, mm, yy)
{
    ID = id;
    pastWorkouts = PastWorkouts;
    isVip = vip;
    visits = Visits;
    subClasses = SubClasses;
    plan = subscription;
}

void Member::setID(long long id)
{
    ID = id;
}

void Member::setVipStatus(bool vip)
{
    isVip = vip;
}

void Member::setVisits(int Visits)
{
    visits = Visits;
}

// Fix Here -> done
void Member::setPlan(int PlanNumber)
{
    plan.setPlan(PlansData::getSubscription(PlanNumber));
}

// Handles All;
void Member::setPlan(const Subscription& sub)
{
    // Name, dur only
    plan = sub;
    plan.setEndDate();
}

void Member::setSubClasses(unordered_set<string> SubClasses)
{
    subClasses = SubClasses;
}

void Member::setEndDate()
{
    plan.setEndDate();
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

int Member::getVisits() const
{
    return visits;
}

unordered_set<string> Member::getSubClasses() const
{
    return subClasses;
}

Date Member::getEndDate() const
{
    return plan.getEndDate();
}

//For Staff
Subscription Member::getPlan()
{
    return plan;
}

void Member::joinClass(string className)
{
    subClasses.insert(className);
}

void Member::leaveClass(string className)
{
    subClasses.erase(className);
}

// Membership functions

void Member::renewPlan()
{
    plan.extendPlan(plan.getName());
}

void Member::cancelPlan()
{
    plan.cancelPlan();
    isVip = 0;
}

void Member::changePlan(string newPlan) 
{
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
        isVip == member.isVip and
        visits == member.visits and
        subClasses == member.subClasses;
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
