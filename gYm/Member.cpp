#include "Member.h"
using namespace std;

Member::Member() : ID(0), isVip(0), visits(0), totalPaid(0) {}

Member::Member(string FirstName, string MiddleName, string LastName, Date dob, long long id, string planName, vector<string> PastWorkouts, bool vip, int Visits, unordered_set<string> SubClasses, Date endDate, int TotalPaid, vector<Slot> Slots) : Person(FirstName, MiddleName, LastName, dob)
{
    ID = id;
    pastWorkouts = PastWorkouts;
    isVip = vip;
    visits = Visits;
    subClasses = SubClasses;
    plan.setPlanName(planName);
    plan.setEndDate();
    totalPaid = TotalPaid;
    slots = Slots;
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

// Sets Name And End Date
void Member::setPlan(int PlanNumber)
{
    plan.setPlanName(PlansData::getName(PlanNumber));
    plan.setEndDate();
}

void Member::setSubClasses(unordered_set<string> SubClasses)
{
    subClasses = SubClasses;
}

void Member::setTotalPaid(int TotalPaid)
{
    totalPaid = TotalPaid;
}

void Member::setSlots(vector<Slot> Slots)
{
    slots = Slots;
}

bool Member::getVipStatus() const
{
    return isVip;
}

void Member::addWorkout(string workout)
{
    pastWorkouts.push_back(workout);
}

void Member::removeSlot(const Slot& slot)
{
    for (int i = 0; i < slots.size(); i++)
    {
        if (slots[i] == slot)
            slots.erase(slots.begin() + i);
    }
}

void Member::addSlot(const Slot& slot)
{
    slots.push_back(slot);
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

int Member::getVisits() const
{
    return visits;
}

int Member::getTotalPaid() const
{
    return totalPaid;
}

unordered_set<string> Member::getSubClasses() const
{
    return subClasses;
}

Date Member::getEndDate() const
{
    return plan.getEndDate();
}

vector<Slot> Member::getSlots() const
{
    return slots;
}

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
}

void Member::changePlan(string newPlan) 
{
    plan.changePlan(newPlan);
}

bool Member::operator == (const Member& member)
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
        subClasses == member.subClasses and
        totalPaid == member.totalPaid and
        slots == member.slots;
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
    cout << isVip << "\n";
    cout << totalPaid << "\n";
}
