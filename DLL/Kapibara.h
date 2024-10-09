#pragma once
#include"Animals.h"
class DLL_API Kapibara: public Animals
{
	string Name;
	string Volier;
	string Class;
	map<int, string> Days;
public:
	Kapibara();
	Kapibara(const Kapibara& obj);
	~Kapibara();
	string Get_Name();
	string Get_Volier();
	string Get_Class();
	string Get_Days();
	bool Proverka_Na_Den(BSTR dannye);
	void Days_Dly_Zapisi(vector<int>& Result);
	Animals* Copy();
};

