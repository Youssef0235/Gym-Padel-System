#pragma once
#include <vector>
#include "Staff.h"
#include "ClassSession.h"

class Coach : public Staff
{
private:
    vector<ClassSession> assignedClasses;
    string className;
public:
    Coach();
    Coach(string firstName, string middleName, string lastName, string ClassName, Date dob, long long id, vector<ClassSession>AssignedClasses, int Salary);

    void setClassName(string ClassName);

    string getClassName() const;

    void assignClass(const ClassSession& classSession);
    void removeClass(long long classId);
    vector<ClassSession> getAssignedClasses() const;
    void clearAssignedClasses();

    // for debug
    void displayClasses();
};