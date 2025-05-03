#pragma once
#include<iostream>
#include<fstream>
#include"json.hpp"
#include<queue>
#include"ClassSession.h"
#include"Member.h"
#include"Coach.h"
#include"Court.h"
using json = nlohmann::json;
using namespace std;


class FileManager
{
public:
	FileManager();
	static map<long long, Member>members;
	static map<long long, Coach>coachesInfo;
	static map<long long, Court>courts;
	static unordered_map<string, queue<long long>>waitingLists;
	static unordered_map<string, queue<long long>>vipWaitingList;
	static unordered_map<string, ClassSession>classes;

	// Working
	static void loadAccounts();
	static void saveAccounts();

	// Working
	static void loadClasses();
	static void saveClasses();

	// Working 
	static void loadWaitLists();
	static void saveWaitLists();

	// Working
	static void loadVipWaitingList();
	static void saveVipWaitingList();

	// Working
	static void loadCoachesInfo();
	static void saveCoachesInfo();

	// Working
	static void loadCourts();
	static void saveCourts();

	// Handle If Sub Ended
	static void handleSubscriptions();
  
	// At End Of Month
	static void clearWaitingList();
	static void clearVipWaitingList();
	static void clearMembersInClasses();
	static void clearCoachesAssignedClasses();
	static void clearVisits();
	static void clearVip();
	static void clearTotalPaid();


	// Utilities
	static long long getLastMemberId();
	static long long getLastCoachId();
	static int getTotalRevenue();
	static vector<long long> getMostActive(int visitsCount);
	static bool matchingNameAndId(string firstName, string middleName, string lastName, long long id);

	// Needs Testing
	static void addToClass(string className, long long memberId);
	static void removeFromClass(string className, long long memberId);
	static void addToWaiting(string className, long long memberId);
	static void removeFromWaiting(string className);
	static void removeMemberFromGym(long long memberId);

	// Wait
	static bool fileExist(string fileName);
	static void createFile(string name);
};