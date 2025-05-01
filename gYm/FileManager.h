#pragma once
#include<iostream>
#include<fstream>
#include"json.hpp"
#include<queue>
#include"ClassInfo.h"
#include"Member.h"
#include"Coach.h"
using json = nlohmann::json;
using namespace std;


class FileManager
{
public:
	FileManager();
	static map<long long, Member>members;
	static map<long long, Coach>coachesInfo;
	static unordered_map<string, queue<Member>>waitingLists;
	static unordered_map<string, ClassInfo>classes;
	static unordered_map<string, queue<Member>>vipWaitingList;

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
  
	// At End Of Month
	static void clearWaitingList();
	static void clearVipWaitingList();


	// Utilities
	static long long getLastId();
	static bool matchingNameAndId(string firstName, string middleName, string lastName, long long id);


	// Needs Testing
	static void addToClass(string className, const Member& member);
	static void removeFromClass(string className, const Member& member);
	static void addToWaiting(string className, const Member& member);
	static void removeFromWaiting(string className);
	static void removeMemberFromGym(const Member& member);


	// Wait
	static bool fileExist(string fileName);
	static void createFile(string name);
};