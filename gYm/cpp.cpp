#include<iostream>
#include<map>
#include<vector>
#include<set>
#include"Subscription.h"
#include"FileManager.h"
#include"Member.h"
#include"ClassSession.h"
#include"Court.h"
#include"BookingSystem.h"
#include"Receptionist.h"
#include"Manager.h"
#define ll long long
using namespace std;


int main()
{
	FileManager::Load();
	FileManager::handleSubscriptions();
	BookingSystem::checkSlotTimePassed();


	cout << "F M L\n";
	string f, m, l; cin >> f >> m >> l;
	cout << "Id\n";
	ll id; cin >> id;
	if (FileManager::matchingNameAndId(f, m, l, id))
	{
		cout << "Welcome To Padel System\n";
		cout << "To Check Your Reservations Press 1\n";
		cout << "To Make A Reservation Press 2\n";
		cout << "To Cancel A Reservation Press 3\n";
		int k; cin >> k;
		if (k == 1)
		{
			cout << "Your Slots:\n";
			vector<Slot>st = FileManager::members[id].getSlots();
			auto it = st.begin();
			while (it != st.end())
			{
				cout << "Location: " << FileManager::courts[it->getCourtID()].getLocation() << "\n";
				it++;
			}
		}
		else if (k == 2)
		{
			vector<Court>v;
			for (int i = 1; i <= 20; i++)
			{
				v.push_back(FileManager::courts[i]);
				cout << "Location: ";
				cout << v.back().getLocation() << "\n";
				cout << "Name: ";
				cout << v.back().getName() << "\n";
			}
			while (1)
			{
				cout << "Choose Court Number: \n";
				int k; cin >> k;
				if (k == -1) break;
				cout << "Enter Day\n";
				int d; cin >> d;
				cout << "Enter Month\n";
				int m; cin >> m;
				cout << "Enter Year\n";
				int y; cin >> y;
				Date date(d, m, y);
				cout << "Enter Hour\n";
				int h; cin >> h;
				Slot newSlot(v[k - 1].getID(), h, date);
				if (Date::isFutureDate(date))
				{
					if (BookingSystem::isSlotAvailable(newSlot))
					{
						BookingSystem::makeBooking(newSlot, id);
						cout << "Done\n";
					}
					else
					{
						cout << "Next Available Slot\n";
						newSlot = BookingSystem::searchNext(date, h, v[k - 1].getLocation());
						cout << "Hour\n";
						cout << newSlot.getHour() << "\n";
						cout << "Day\n";
						cout << newSlot.getDate().getDay() << "\n";
						cout << "Month\n";
						cout << newSlot.getDate().getMonth() << "\n";
						cout << "Year\n";
						cout << newSlot.getDate().getYear() << "\n";
						cout << "To Book Next Available Slot Press 1\n";
						int p; cin >> p;
						if (p == 1)
						{
							BookingSystem::makeBooking(newSlot, id);
							cout << "Done\n";
						}
					}
				}
				else
				{
					cout << "Date Is Invalid\n";
				}
			}
		}
		else
		{
			cout << "Your Slots:\n";
			vector<Slot>st = FileManager::members[id].getSlots();
			auto it = st.begin();
			int count = 1;
			vector<Slot>v;
			while (it != st.end())
			{
				v.push_back(*it);
				cout << "Slot Number: " << count << "\n";
				cout << "At: " << it->getHour() << "\n";
				cout << "Location: " << FileManager::courts[it->getCourtID()].getLocation() << "\n";
				cout << "Court Name: " << FileManager::courts[it->getCourtID()].getName() << "\n";
				it++, count++;
			}
			if (v.empty())
				return 0;
			cout << "Enter Slot Number To Cancel\n";
			int c; cin >> c;
			if (BookingSystem::cancelBooking(id, v[c - 1]))
			{
				cout << "Success\n";
			}
			else
			{
				cout << "Cannot Cancel\n";
			}
		}
	}

	FileManager::Save();

	return 0;
}