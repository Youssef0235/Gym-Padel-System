#pragma once
#include<iostream>
using namespace std;


// For Reading Only
class PlansData
{
public:
	static string getName(int number);
	static int getDuration(int number);
	static int getDuration(string planName);
	static int getPrice(int number);
};