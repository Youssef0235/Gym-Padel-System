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
	FileManager::loadCoachesInfo();

	string f, m, l;
	cout << "Enter First Name\n";
	cin >> f;
	cout << "Enter Middle Name\n";
	cin >> m;
	cout << "Enter Last Name\n";
	cin >> l;
	cout << "Enter Id\n";

	ll id; cin >> id;
	if (FileManager::matchingNameAndId(f, m, l, id))
	{
		cout << "For Gym Press 1\n";
		cout << "For Padel Press 2\n";
		cout << "For Classes Press 3\n";
		int c; cin >> c;
		if (c == 1)
		{
			if (FileManager::members[id].getPlanName() != "")
			{
				cout << "To Train Press 1\n";
				cout << "To Cancel Sub Press 2\n";
				cout << "To Renew Sub Press 3\n";
				cout << "To Change Sub Press 4\n";
				cout << "To View Recent Workouts Press 5\n";
				int k; cin >> k;
				if (k == 1)
				{
					bool x = 1;
					FileManager::members[id].setVisits(FileManager::members[id].getVisits() + 1);
					while (x)
					{
						cout << "Enter Workout Name\n";
						string s; cin >> s;
						FileManager::members[id].addWorkout(s);
						cout << "To Leave Press 0\n";
						cout << "To Carry On Press 1\n";
						cin >> x;
					}
				}
				else if(k == 2)
				{
					FileManager::members[id].cancelPlan();
				}
				else if (k == 3)
				{
					FileManager::members[id].renewPlan();
				}
				else if (k == 4)
				{
					cout << "For Basic Plan Press 1\n";
					cout << "For Standard Plan Press 2\n";
					cout << "For Premium Plan Press 3\n";
					cout << "For Ultimate Plan Press 4\n";
					int x; cin >> x;
					FileManager::members[id].setPlan(x);
					if (!FileManager::members[id].getVipStatus())
					{
						cout << "To Become Vip Press 1\n";
						cin >> x;
						FileManager::members[id].setVipStatus(x);
					}
				}
				else if(k == 5)
				{
					cout << "Recent Workouts:\n";
					vector<string>v = FileManager::members[id].getPastWorkouts();
					for (int i = 0; i < v.size(); i++)
					{
						cout << v[i];
						if (i + 1 == v.size())
							cout << "\n";
						else
							cout << ", ";
					}
				}
			}
			else
			{
				cout << "You Need To Sub First\n";
				/*
				cout << "Enter First Name\n";
				string fName; cin >> fName;
				cout << "Enter Middle Name\n";
				string mName; cin >> fName;
				cout << "Enter Last Name\n";
				string lName; cin >> fName;
				cout << "Enter Day Of Birth\n";
				int dd; cin >> dd;
				cout << "Enter Month Of Birth\n";
				int mm; cin >> mm;
				cout << "Enter Year Of Birth\n";
				int yy; cin >> yy;
				*/
				cout << "For Basic Plan Press 1\n";
				cout << "For Standard Plan Press 2\n";
				cout << "For Premium Plan Press 3\n";
				cout << "For Ultimate Plan Press 4\n";
				int x; cin >> x; 
				cout << "To Become Vip Press 1\n";
				int v; cin >> v;
				Subscription sub = PlansData::getSubscription(x);
				cout << "Thank You!\n";
				//ll newId = FileManager::getLastMemberId() + 1;
				//Member newMember(fName, mName, lName, dd, mm, yy, newId, sub, {}, v, 0, {});
				FileManager::members[id].setPlan(sub);
			}
		}
		if (c == 2)
		{

		}
		if (c == 3)
		{
			bool x = 1;
			while (x)
			{
				cout << "To Sub To Class Press 1\n";
				cout << "To Cancel A Class Press 2\n";
				cout << "To Check Your Classes Press 3\n";
				cout << "To Leave Press 4\n";
				int k; cin >> k;
				if (k == 1)
				{
					cout << "Available Classes:\n";
					auto it = FileManager::classes.begin();
					while (it != FileManager::classes.end())
					{
						cout << it->first << "\n";
						it++;
					}
					cout << "Enter Class To Sub To\n";
					string s; cin >> s;
					if (FileManager::classes[s].getClassMembers().size() < FileManager::classes[s].getClassCapacity())
					{
						FileManager::classes[s].addMember(id);
						FileManager::members[id].joinClass(s);
						cout << "Joined Class Successfully\n";
					}
					else
					{
						cout << "You Joined Class Waiting List\n";
						if (FileManager::members[id].getVipStatus())
							FileManager::vipWaitingList[s].push(id);
						else
							FileManager::waitingLists[s].push(id);
					}
				}
				else if (k == 2)
				{
					unordered_set<string> v = FileManager::members[id].getSubClasses();
					if (v.size())
					{
						cout << "Your Classes:\n";
						auto it = v.begin();
						while (it != v.end())
							cout << *it << " ";
						cout << "\n";
					}
					cout << "Enter Class To Cancel\n";
					string s; cin >> s;
					FileManager::members[id].leaveClass(s);
				}
				else if (k == 3)
				{
					unordered_set<string> v = FileManager::members[id].getSubClasses();
					if (v.size())
					{
						cout << "Your Classes:\n";
						auto it = v.begin();
						while (it != v.end())
							cout << *it << " ";
						cout << "\n";
					}
					else
					{
						cout << "You Dont Have Any Pending Classes\n";
					}
				}
				else
					break;
			}
		}
	}
	else
	{
		cout << "You Need To Be A Member First\n";
		cout << "Enter First Name\n";
		string fName; cin >> fName;
		cout << "Enter Middle Name\n";
		string mName; cin >> fName;
		cout << "Enter Last Name\n";
		string lName; cin >> fName;
		cout << "Enter Day Of Birth\n";
		int dd; cin >> dd;
		cout << "Enter Month Of Birth\n";
		int mm; cin >> mm;
		cout << "Enter Year Of Birth\n";
		int yy; cin >> yy;
		cout << "For Basic Plan Press 1\n";
		cout << "For Standard Plan Press 2\n";
		cout << "For Premium Plan Press 3\n";
		cout << "For Ultimate Plan Press 4\n";
		int x; cin >> x;
		cout << "To Become Vip Press 1\n";
		int v; cin >> v;
		Subscription sub = PlansData::getSubscription(x);
		cout << "Thank You!\n";
		ll newId = FileManager::getLastMemberId() + 1;
		Member newMember(fName, mName, lName, dd, mm, yy, newId, sub, {}, v, 0, {});
		FileManager::members[id].setPlan(sub);
	}

	FileManager::saveAccounts();
	FileManager::saveClasses();
	FileManager::saveWaitLists();
	FileManager::saveVipWaitingList();
	FileManager::saveCoachesInfo();

	return 0;
}