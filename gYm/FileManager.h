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
public:
	FileManager();
	static map<long long, Member>members;
	static map<long long, Coach>coachesInfo;
	static map<long long, Court>courts;
	static unordered_map<string, queue<long long>>waitingLists;
	static unordered_map<string, queue<long long>>vipWaitingList;
	static unordered_map<string, ClassSession>classes;

	// Work
	static void Load();
	static void Save();
	static void itsFirstDay();


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


	// -------------------- GYM ---------------------------- //
	// Handle If Sub Ends
	static void handleSubscriptions();

	// At End Of Month
	static void clearWaitingList();
	static void clearVipWaitingList();
	static void clearMembersInClasses();
	static void clearVisits();
	static void clearTotalPaid();
	// -------------------- GYM ---------------------------- //


	// -------------------------- CLASSES ---------------------------------- //
	static void addToClass(string className, long long memberId);
	static void removeFromClass(string className, long long memberId);
	static void addToWaiting(string className, long long memberId);
	static long long getFirstInWaiting(string className);
	static void removeMemberFromGym(long long memberId);
	// -------------------------- CLASSES ---------------------------------- //


	// Utilities
	static void clearInbox(long long memberId);
	static string getClassName(int id);
	static long long getLastMemberId();
	static long long getLastCoachId();
	static long long getLastCourtId();
	static bool matchingNameAndId(string firstName, string middleName, string lastName, long long id);


	// Wait
	static bool fileExist(string fileName);
	static void createFile(string name);
};