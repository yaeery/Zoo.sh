#include "Animals.h"
Animals::Animals()
{
	
}
Animals:: ~Animals(){}
string Animals::Get_Name()
{
	return Name;
}
string Animals::Get_Volier()
{
	return Volier;
}
string Animals::Get_Class()
{
	return Class;
}
string Animals::Get_Days()
{
	string x;
	map<int, string> ::iterator first = Days.begin();//begin();
	map<int, string> ::iterator second = Days.end();
	second--;
	x = x + first->second + " - " + second->second;
	return x;
}
bool Animals::Proverka_Na_Den(BSTR stroka)
{
	return false;
}

void Animals::Days_Dly_Zapisi(vector<int>& Result)
{
	Result.clear();
	Result.push_back(10000);
}
Animals* Animals::Copy()
{
	return new Animals(*this);
}
Animals::Animals(const Animals& obj)
{
	Name = obj.Name;
	Class = obj.Class;
	Volier = obj.Volier;
	Days = obj.Days;
}
