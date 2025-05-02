#pragma once
#include<iostream>
#include "Subscription.h"
using namespace std;

class Subscription;

// For Reading Only
class PlansData
{
public:
	static string getName(int number);
	static int getDuration(int number);
	static int getDuration(string planName);
	static int getPrice(int number);
    static Subscription getSubscription(int number);
};