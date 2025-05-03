#include<iostream>
#include<map>
#include<vector>
#include<set>
#include"Subscription.h"
#include"FileManager.h"
#include"Member.h"
#include"ClassSession.h"
#include"Court.h"
#define ll long long
using namespace std;


int main()
{
	FileManager::loadAccounts();
	FileManager::loadClasses();
	//FileManager::loadWaitLists();
	//FileManager::loadVipWaitingList();
	FileManager::loadCoachesInfo();
	FileManager::handleSubscriptions();
	FileManager::loadCourts();



	FileManager::saveAccounts();
	FileManager::saveClasses();
	FileManager::saveWaitLists();
	FileManager::saveVipWaitingList();
	FileManager::saveCoachesInfo();
	FileManager::saveCourts();

	return 0;
}