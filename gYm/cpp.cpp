#include<iostream>
#include<map>
#include<vector>
#include"Subscription.h"
#include"FileManager.h"
#include"Member.h"
#include"ClassInfo.h"
#define ll long long
using namespace std;


class message
{
private:
	string text;
	bool read;
public:
	message() : read(0) {}
	message(string s) : read(0), text(s) {}
};

void sendMessage(message m, Member mem)
{
}



int main()
{
	FileManager::loadAccounts();
	FileManager::loadClasses();
	FileManager::loadWaitLists();
	FileManager::loadVipWaitingList();
	FileManager::loadCoachesInfo();




	FileManager::saveAccounts();
	FileManager::saveClasses();
	FileManager::saveWaitLists();
	FileManager::saveVipWaitingList();
	FileManager::saveCoachesInfo();

	return 0;
}