#pragma once
#include<iostream>
using namespace std;

// For Reading Only
class PlansData
{
public:
	static int getDuration(string planName);
	static int getPrice(string planName);
};