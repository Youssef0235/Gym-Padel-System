#include "FileManager.h"

// ifstream -> read
// ofstream -> write

// From Json Uses Class Constructor

// Map Uses Self Balancing Tree -> Red Black Tree So Retrieval Is In O(Log n)
map<long long, Member> FileManager::members;
map<long long, Coach> FileManager::coachesInfo;
map<long long, Court> FileManager::courts;
unordered_map<string, queue<long long>> FileManager::waitingLists;
unordered_map<string, queue<long long>>FileManager::vipWaitingList;
unordered_map<string, ClassSession> FileManager::classes;


FileManager::FileManager() {}

void FileManager::Load()
{
	loadAccounts();
	loadClasses();
	loadWaitLists();
	loadVipWaitingList();
	loadCoachesInfo();
	loadCourts();
}

void FileManager::Save()
{
	saveAccounts();
	saveClasses();
	saveWaitLists();
	saveVipWaitingList();
	saveCoachesInfo();
	saveCourts();
}

void FileManager::loadAccounts()
{
	json Accounts;
	// Open Accounts File
	ifstream file("Accounts.json");
	// Load To Accounts
	try
	{
		file >> Accounts;
	}
	catch (...) {}	
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
		string id = to_string(it->second.getID());
		Accounts[id] = it->second;
		it++;
	}
	ofstream file("Accounts.json");
	file << Accounts.dump(4);
	file.close();
}

void FileManager::loadClasses()
{
	ifstream file("Classes.json");
	json Classes;
	try
	{
		file >> Classes;
	}
	catch (...) {}
	auto it = Classes.begin();
	while (it != Classes.end())
	{
		classes[it.key()] = it.value();
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
		Classes[it->first] = it->second;
		it++;
	}
	file << Classes.dump(4);
	file.close();
}



void FileManager::loadWaitLists()
{
	json waitingListsJson;
	ifstream file("WaitLists.json");
	try
	{
		file >> waitingListsJson;
	}
	catch (...) {}
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
	try
	{
		file >> waitingListsJson;
	}
	catch (...) {}	file.close();
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




void FileManager::loadCoachesInfo()
{
	json CoachesInfo;
	ifstream file("Coaches Info.json");
	try
	{
		file >> CoachesInfo;
	}
	catch (...) {}
	file.close();
	auto it = CoachesInfo.begin();
	while (it != CoachesInfo.end())
	{
		long long id = stoll(it.key());
		coachesInfo[id] = it.value();
		it++;
	}
}

void FileManager::saveCoachesInfo()
{
	json CoachesInfo;
	auto it = coachesInfo.begin();
	while (it != coachesInfo.end())
	{
		string id = to_string(it->second.getID());
		CoachesInfo[id] = it->second;
		it++;
	}
	ofstream file("Coaches Info.json");
	file << CoachesInfo.dump(4);
	file.close();
}


void FileManager::loadCourts()
{
	json Courts;
	ifstream file("Courts.json");
	try
	{
		file >> Courts;
	}
	catch (...) {}	
	file.close();
	auto it = Courts.begin();
	while (it != Courts.end())
	{
		courts[stoll(it.key())] = it.value();
		it++;
	}
}

void FileManager::saveCourts()
{
	json Courts;
	auto it = courts.begin();
	while (it != courts.end())
	{
		string id = to_string(it->first);
		Courts[id] = it->second;
		it++;
	}
	ofstream file("Courts.json");
	file << Courts.dump(4);
	file.close();
}

void FileManager::itsFirstDay()
{
	if (Date::isFirstDay() && Date::isNow("23:59:59"))
	{
		clearWaitingList();
		clearVipWaitingList();
		clearMembersInClasses();
		clearVisits();
		clearTotalPaid();
		clearVip();
	}
}

void FileManager::handleSubscriptions()
{
	auto it = members.begin();
	while (it != members.end())
	{
		Date userEndDate = members[it->first].getEndDate();
		if (!Date::isFutureDate(userEndDate))
			members[it->first].cancelPlan();
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

void FileManager::clearVisits()
{
	auto it = members.begin();
	while (it != members.end())
	{
		members[it->first].setVisits(0);
		it++;
	}
}

void FileManager::clearTotalPaid()
{
	auto it = members.begin();
	while (it != members.end())
	{
		members[it->first].setTotalPaid(0);
		it++;
	}
}

void FileManager::clearVip()
{
	auto it = members.begin();
	while (it != members.end())
	{
		members[it->first].setVipStatus(0);
		it++;
	}
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

bool FileManager::isStaff(string firstName, string middleName, string lastName, long long id)
{
	if (firstName == middleName and middleName == lastName and id >= 1 and id <= 16)
		return true;
	return false;
}

string FileManager::staffRole(long long id)
{
	if (id == 1)
		return "Manager";
	else if (id >= 2 and id <= 6)
		return "Receptionist";
	else
		return "Coach";
}

void FileManager::clearInbox(long long memberId)
{
	members[memberId].clearInbox();
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