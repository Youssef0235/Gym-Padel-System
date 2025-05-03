#include "FileManager.h"

// ifstream -> read
// ofstream -> write

// From Json Uses Class Constructor

// Map Uses Self Balancing Tree -> Red Black Tree So Retrieval Is In O(Log n)
map<long long, Member> FileManager::members;
map<long long, Coach> FileManager::coachesInfo;
unordered_map<string, queue<long long>> FileManager::waitingLists;
unordered_map<string, queue<long long>>FileManager::vipWaitingList;
unordered_map<string, ClassSession> FileManager::classes;

FileManager::FileManager() {}

void from_json(const json& j, Date& u)
{
	u = Date
	{
		j.at("Day").get<int>(),
		j.at("Month").get<int>(),
		j.at("Year").get<int>(),
	};
}

void to_json(json& j, const Date& u)
{
	j = json
	{
		{"Day", u.getDay()},
		{"Month", u.getMonth()},
		{"Year", u.getYear()},
	};
}

void from_json(const json& j, Member& u)
{
	u = Member
	{
		j.at("First Name").get<string>(),
		j.at("Middle Name").get<string>(),
		j.at("Last Name").get<string>(),
		j.at("Birth Date").get<Date>(),
		j.at("ID").get<long long>(),
		j.at("Plan").get<string>(),
		j.at("Past Workouts").get<vector<string>>(),
		j.at("VIP").get<bool>(),
		j.at("Visits").get<int>(),
		j.at("Classes").get<unordered_set<string>>(),
		j.at("End Date").get<Date>()
	};
}

void to_json(json& j, const Member& u)
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
	};
}

void FileManager::loadAccounts()
{
	json Accounts;
	// Open Accounts File
	ifstream file("Accounts.json");
	// Load To Accounts
	file >> Accounts;
	file.close();
	// User Exists, Look For Matching ID
	auto it = Accounts.begin();
	while (it != Accounts.end())
	{
		long long id = stoll(it.key());
		members[id] = it.value();
		it++;
	}
}


void FileManager::saveAccounts()
{
	json Accounts;	
	auto it = members.begin();
	while (it != members.end())
	{
		string id = to_string(it->first);
		Accounts[id] = it->second;
		it++;
	}
	ofstream file("Accounts.json");
	file << Accounts.dump(4);
	file.close();
}


void to_json(json& j, const ClassSession& u)
{
	j = json
	{
		{"Day", u.getClassDay()},
		{"Time", u.getClassTime()},
		{"Name", u.getClassName()},
		{"Capacity", u.getClassCapacity()},
		{"Members", u.getClassMembers()},
	    {"Class ID",u.getCoachId()},
		{"Coach ID",u.getClassId()}
	};
}


void from_json(const json& j, ClassSession& u)
{
	u = ClassSession
	{
		j.at("Day").get<string>(),
		j.at("Time").get<string>(),
		j.at("Name").get<string>(),
		j.at("Capacity").get<int>(),
		j.at("Members").get<unordered_set<long long>>(),
		j.at("Class ID").get<long long>(),
		j.at("Coach ID").get<long long>()
	};
}


void FileManager::loadClasses()
{
	ifstream file("Classes.json");
	json Classes;
	file >> Classes;
	auto it = Classes.begin();
	while (it != Classes.end())
	{
		string className = it.key();
		classes[className] = it.value();
		it++;
	}
}

void FileManager::saveClasses()
{
	ofstream file("Classes.json");
	json Classes;
	auto it = classes.begin();
	while (it != classes.end())
	{
		string className = it->first;
		Classes[className] = it->second;
		it++;
	}
	file << Classes.dump(4);
	file.close();
}



void FileManager::loadWaitLists()
{
	json waitingListsJson;
	ifstream file("WaitLists.json");
	file >> waitingListsJson;
	file.close();
	auto it = waitingListsJson.begin();
	while (it != waitingListsJson.end())
	{
		string className = it.key();
		for (long long memberId : it.value())
			waitingLists[className].push(memberId);
		it++;
	}
}

void FileManager::saveWaitLists()
{
	json waitingListsJson;
	auto it = waitingLists.begin();
	while (it != waitingLists.end())
	{
		queue<long long>currentClass = it->second;
		string className = it->first;
		while (currentClass.size())
		{
			waitingListsJson[className].push_back(currentClass.front());
			currentClass.pop();
		}
		it++;
	}
	ofstream file("WaitLists.json");
	file << waitingListsJson.dump(4);
	file.close();
}

void FileManager::loadVipWaitingList()
{
	json waitingListsJson;
	ifstream file("Vip WaitingLists.json");
	file >> waitingListsJson;
	file.close();
	auto it = waitingListsJson.begin();
	while (it != waitingListsJson.end())
	{
		string className = it.key();
		for (long long memberId : it.value())
			vipWaitingList[className].push(memberId);
		it++;
	}
}


void FileManager::saveVipWaitingList()
{
	json waitingListsJson;
	auto it = vipWaitingList.begin();
	while (it != vipWaitingList.end())
	{
		queue<long long>currentClass = it->second;
		string className = it->first;
		while (currentClass.size())
		{
			waitingListsJson[className].push_back(currentClass.front());
			currentClass.pop();
		}
		it++;
	}
	ofstream file("Vip WaitingLists.json");
	file << waitingListsJson.dump(4);
	file.close();
}

void from_json(const json& j, Coach& u) 
{
	u = Coach
	{
		j.at("First Name").get<string>(),
		j.at("Middle Name").get<string>(),
		j.at("Last Name").get<string>(),
		j.at("Class").get<string>(),
		j.at("Birth Date").get<Date>(),
		j.at("ID").get<long long>(),
		j.at("Assigned Classes").get<vector<ClassSession>>()
	};
}


void FileManager::loadCoachesInfo()
{
	json CoachesInfo;
	ifstream file("Coaches Info.json");
	file >> CoachesInfo;
	file.close();
	auto it = CoachesInfo.begin();
	while (it != CoachesInfo.end())
	{
		long long id = stoll(it.key());
		coachesInfo[id] = it.value();
		it++;
	}
}


void to_json(json& j, const Coach& u)
{
	j = json
	{
		{"First Name", u.getFname()},
		{"Middle Name", u.getMname()},
		{"Last Name", u.getLname()},
		{"Class", u.getClassName()},
        {"Birth Date", u.getDateOfBirth()},
		{"ID", u.getID()},
		{"Assigned Classes", u.getAssignedClasses()}
	};
}

void FileManager::saveCoachesInfo()
{
	json CoachesInfo;
	auto it = coachesInfo.begin();
	while (it != coachesInfo.end())
	{
		string id = to_string(it->first);
		CoachesInfo[id] = it->second;
		it++;
	}
	ofstream file("Coaches Info.json");
	file << CoachesInfo.dump(4);
	file.close();
}

void FileManager::handleSubscriptions()
{
	auto it = members.begin();
	while (it != members.end())
	{
		Date userEndDate = members[it->first].getEndDate();
		if (!Date::isFutureDate(userEndDate))
			members[it->first].resetSubscription();
		it++;
	}
}

void FileManager::clearWaitingList()
{
	auto it = waitingLists.begin();
	while (it != waitingLists.end())
	{
		while (waitingLists[it->first].size())
			waitingLists[it->first].pop();
		it++;
	}
}

void FileManager::clearVipWaitingList()
{
	auto it = vipWaitingList.begin();
	while (it != vipWaitingList.end())
	{
		while (vipWaitingList[it->first].size())
			vipWaitingList[it->first].pop();
		it++;
	}
}

void FileManager::clearMembersInClasses()
{
	auto it = classes.begin();
	while (it != classes.end())
	{
		classes[it->first].clearClassMembers();
		it++;
	}
}

void FileManager::clearCoachesAssignedClasses()
{
	auto it = coachesInfo.begin();
	while (it != coachesInfo.end())
	{
		coachesInfo[it->first].clearAssignedClasses();
		it++;
	}
}

void FileManager::clearVisits()
{
	auto it = members.begin();
	while (it != members.end())
	{
		members[it->first].setVisits(0);
		it++;
	}
}

long long FileManager::getLastMemberId()
{
	return members.rbegin()->first;
}

long long FileManager::getLastCoachId()
{
	return coachesInfo.rbegin()->first;
}

bool FileManager::matchingNameAndId(string firstName, string middleName, string lastName, long long id)
{
	if (members.find(id) == members.end())
		return false;
	string fName = members[id].getFname();
	string mName = members[id].getMname();
	string lName = members[id].getLname();
	return fName == firstName && mName == middleName && lName == lastName;
}

void FileManager::addToClass(string className, long long memberId)
{
	classes[className].addMember(memberId);
}

void FileManager::removeFromClass(string className, long long memberId)
{
	classes[className].removeMember(memberId);
}

void FileManager::addToWaiting(string className, long long memberId)
{
	if (members[memberId].getVipStatus())
		vipWaitingList[className].push(memberId);
	else
		waitingLists[className].push(memberId);
}

void FileManager::removeFromWaiting(string className)
{
	if (vipWaitingList[className].size())
		vipWaitingList[className].pop();

	else if (waitingLists[className].size())
		waitingLists[className].pop();
}

void FileManager::removeMemberFromGym(long long memberId)
{
	members.erase(memberId);
}

bool FileManager::fileExist(string fileName)
{
	ifstream file(fileName + ".json");
	return file.good();
}


void FileManager::createFile(string name)
{
	// Check If File Already Exists
	if (fileExist(name))
		return;

	// Create A New One
	ofstream file(name + ".json");
	file.close();
}