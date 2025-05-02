#include<iostream>
#include<map>
#include<vector>
#include<set>
#include"Subscription.h"
#include"FileManager.h"
#include"Member.h"
#include"ClassSession.h"
#define ll long long
using namespace std;


int main()
{
	FileManager::loadAccounts();
	FileManager::loadClasses();
	FileManager::loadWaitLists();
	FileManager::loadVipWaitingList();
	//FileManager::loadCoachesInfo();



	FileManager::saveAccounts();
	FileManager::saveClasses();
	FileManager::saveWaitLists();
	FileManager::saveVipWaitingList();
	//FileManager::saveCoachesInfo();

	return 0;
}