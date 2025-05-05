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

	// Load And Save All
	static void Load();
	static void Save();

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

	// Handle If Sub Ends
	static void handleSubscriptions();
	// Handle If Reservation Ends
	//static void handleSlots();
  
	// At End Of Month
	static void clearWaitingList();
	static void clearVipWaitingList();
	static void clearMembersInClasses();
	static void clearCoachesAssignedClasses();
	static void clearVisits();
	static void clearVip();
	static void clearTotalPaid();


	// Utilities
	static string getClassName(int id);
	static long long getLastMemberId();
	static long long getLastCoachId();
	static long long getLastCourtId();
	static int getTotalRevenue();
	static bool comp(const Member& a, const Member& b);
	static vector<long long> getMostActive();
	static bool matchingNameAndId(string firstName, string middleName, string lastName, long long id);


	static void addToClass(string className, long long memberId);
	static void removeFromClass(string className, long long memberId);
	static void addToWaiting(string className, long long memberId);
	static void removeFromWaiting(string className);
	static void removeMemberFromGym(long long memberId);
	static void removeSlot(long long memberId, const Slot& slot);

	static void addCourt(string Location, string CourtName);
	static long long getCourtId(string location);
	static bool foundSlot(long long memberId, const Slot& slot);

	// Wait
	static bool fileExist(string fileName);
	static void createFile(string name);
};