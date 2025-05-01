#pragma once
#include <vector>
#include "Staff.h"
#include "ClassInfo.h"

class Coach : public Staff
{
private:
    vector<ClassInfo> assignedClasses;
    string className;
public:
    Coach();
    Coach(string firstName, string middleName, string lastName, string ClassName, int dd, int mm, int yy, long long id, vector<ClassInfo>AssignedClasses);

    void setClassName(string ClassName);
    string getClassName() const;

    void assignClass(const ClassInfo& classInfo);
    void removeClass(long long classId);
    vector<ClassInfo> getAssignedClasses() const;
    // for debug
    void displayClasses();
};