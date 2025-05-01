#include "FileManager.h"

// ifstream -> read
// ofstream -> write

// From Json Uses Class Constructor

// Map Uses Self Balancing Tree -> Red Black Tree So Retrieval Is In O(Log n)
map<long long, Member> FileManager::members;
map<long long, Coach> FileManager::coachesInfo;
unordered_map<string, queue<Member>> FileManager::waitingLists;
unordered_map<string, ClassInfo> FileManager::classes;
unordered_map<string, queue<Member>>FileManager::vipWaitingList;

FileManager::FileManager()
{
}

void from_json(const json& j, Member& u)
{
	u = Member
	{
		j.at("First Name").get<string>(),
		j.at("Middle Name").get<string>(),
		j.at("Last Name").get<string>(),
		j.at("Day").get<int>(),
		j.at("Month").get<int>(),
		j.at("Year").get<int>(),
		j.at("ID").get<long long>(),
		j.at("Plan Name").get<string>(),
		j.at("Duration").get<int>(),
		j.at("Past Workouts").get<vector<string>>(),
		j.at("VIP").get<bool>(),
		j.at("Visits").get<int>()
	};
}

void to_json(json& j, const Member& u)
{
	j = json
	{
		{"First Name", u.getFname()},
		{"Middle Name", u.getMname()},
		{"Last Name", u.getLname()},
		{"Day", u.getDay()},
		{"Month", u.getMonth()},
		{"Year", u.getYear()},
		{"ID", u.getID()},
		{"Plan Name", u.getPlanName()},
		{"Duration", u.getPlanDuration()},
		{"Past Workouts", u.getPastWorkouts()},
		{"VIP", u.getVipStatus()},
		{"Visits", u.getVisits()}
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


void to_json(json& j, const ClassInfo& u)
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


void from_json(const json& j, ClassInfo& u)
{
	u = ClassInfo
	{
		j.at("Day").get<string>(),
		j.at("Time").get<string>(),
		j.at("Name").get<string>(),
		j.at("Capacity").get<int>(),
		j.at("Members").get<set<Member>>(),
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
		for (Member member : it.value())
			waitingLists[className].push(member);
		it++;
	}
}

void FileManager::saveWaitLists()
{
	json waitingListsJson;
	auto it = waitingLists.begin();
	while (it != waitingLists.end())
	{
		queue<Member>currentClass = it->second;
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
		for (Member member : it.value())
			vipWaitingList[className].push(member);
		it++;
	}
}


void FileManager::saveVipWaitingList()
{
	json waitingListsJson;
	auto it = vipWaitingList.begin();
	while (it != vipWaitingList.end())
	{
		queue<Member>currentClass = it->second;
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
		j.at("Day").get<int>(),
		j.at("Month").get<int>(),
		j.at("Year").get<int>(),
		j.at("ID").get<long long>(),
		j.at("Assigned Classes").get<vector<ClassInfo>>()
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
		{"Day", u.getDay()},
		{"Month", u.getMonth()},
		{"Year", u.getYear()},
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

void FileManager::clearWaitingList()
{
	waitingLists.clear();
}

void FileManager::clearVipWaitingList()
{
	vipWaitingList.clear();
}

long long FileManager::getLastId()
{
	return members.rbegin()->first;
}

bool FileManager::matchingNameAndId(string firstName, string middleName, string lastName, long long id)
{
	// Check If User Exists First In O(Log n)
	if (members.find(id) == members.end())
		return false;
	string fName = members[id].getFname();
	string mName = members[id].getMname();
	string lName = members[id].getLname();
	return fName == firstName and mName == middleName and lName == lastName;
}

void FileManager::addToClass(string className, const Member& member)
{
	classes[className].addMember(member);
}

void FileManager::removeFromClass(string className, const Member& member)
{
	classes[className].removeMember(member);
}

void FileManager::addToWaiting(string className, const Member& member)
{
	if (member.getVipStatus())
		vipWaitingList[className].push(member);
	else
		waitingLists[className].push(member);
}

void FileManager::removeFromWaiting(string className)
{
	if (vipWaitingList[className].size())
		vipWaitingList[className].pop();

	else if(waitingLists[className].size())
		waitingLists[className].pop();
}

void FileManager::removeMemberFromGym(const Member& member)
{
	if (members.find(member.getID()) != members.end())
		members.erase(member.getID());
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