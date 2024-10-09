#pragma once
#include"Animals.h"
class DLL_API Pingvin: public Animals
{
	string Name;
	string Volier;
	string Class;
	map<int, string> Days;
public:
	Pingvin();
	Pingvin(const Pingvin& obj);
	~Pingvin();
	string Get_Name();
	string Get_Volier();
	string Get_Class();
	string Get_Days();
	bool Proverka_Na_Den(BSTR dannye);
	void Days_Dly_Zapisi(vector<int>& Result);
	Animals* Copy();
};

