#pragma once
#include<iostream>
#include<fstream>
#include<queue>
#include"json.hpp"
#include"ClassSession.h"
#include"Member.h"
#include"Coach.h"
#include"Court.h"
#include"Slot.h"
#include"Messages.h"
using json = nlohmann::json;
using namespace std;


class FileManager
{
private:
	static void loadAccounts();
	static void saveAccounts();
	static void loadClasses();
	static void saveClasses();
	static void loadWaitLists();
	static void saveWaitLists();
	static void loadVipWaitingList();
	static void saveVipWaitingList();
	static void loadCoachesInfo();
	static void saveCoachesInfo();
	static void loadCourts();
	static void saveCourts();

	// At End Of Month
	static void clearWaitingList();
	static void clearVipWaitingList();
	static void clearMembersInClasses();
	static void clearVisits();
	static void clearTotalPaid();
	static void clearVip();

public:
	FileManager();
	static map<long long, Member>members;
	static map<long long, Coach>coachesInfo;
	static map<long long, Court>courts;
	static unordered_map<string, queue<long long>>waitingLists;
	static unordered_map<string, queue<long long>>vipWaitingList;
	static unordered_map<string, ClassSession>classes;


	static void Load();
	static void Save();
	static void itsFirstDay();

	// Handle Ended Subs
	static void handleSubscriptions();


	// Utilities
	static void clearInbox(long long memberId);
	static bool matchingNameAndId(string firstName, string middleName, string lastName, long long id);
	static bool isStaff(string firstName, string middleName, string lastName, long long id);
	static string staffRole(long long id);


	// Wait
	static bool fileExist(string fileName);
	static void createFile(string name);
};