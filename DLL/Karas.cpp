#include "Karas.h"
Karas::Karas()
{
	Name = "������";
	Volier = "25";
	Class = "����";
	Days.insert(make_pair(1, "�����������"));
	Days.insert(make_pair(2, "�������"));
	Days.insert(make_pair(3, "�����"));
	Days.insert(make_pair(4, "�������"));
	Days.insert(make_pair(5, "�������"));
	Days.insert(make_pair(6, "�������"));
	Days.insert(make_pair(7, "�����������"));
}
string Karas::Get_Name()
{
	return Name;
}
Karas ::~Karas() {}
string Karas::Get_Volier()
{
	return Volier;
}
string Karas::Get_Class()
{
	return Class;
}
string Karas::Get_Days()
{
	string x;
	map<int, string> ::iterator first = Days.begin();
	map<int, string> ::iterator second = Days.end();
	second--;
	x = x + first->second + " - " + second->second;
	return x;
}
bool Karas::Proverka_Na_Den(BSTR dannye)
{
	vector<int> Days_Vectora;
	vector<int> Days_Dannie;
	vector<int> Itog;
	for (map<int, string>::iterator it = Days.begin(); it != Days.end(); it++)
	{
		Days_Vectora.push_back((*it).first);
	}
	char* s = _com_util::ConvertBSTRToString(dannye);
	string stroka = s;
	for_each(stroka.begin(), stroka.end(), [&Days_Dannie](char x) {Days_Dannie.push_back((x)-'0'); });//������ ��������
	set_intersection(Days_Vectora.begin(), Days_Vectora.end(), Days_Dannie.begin(), Days_Dannie.end(), inserter(Itog, Itog.begin())); // �������� ��� �����������
	if (Itog.size() == stroka.size())
	{
		delete s;
		return true;
	}
	else
	{
		delete s;
		return false;
	}
}
void Karas::Days_Dly_Zapisi(vector<int>& Result)
{
	vector<int> Vector;
	vector<int> x;
	for (int i = 0; i < Days.size(); i++)
	{
		Vector.push_back(i + 1);
	}
	set_intersection(Result.begin(), Result.end(), Vector.begin(), Vector.end(), inserter(x, x.begin()));
	Result.swap(x);	//������ ��������
}

Animals* Karas::Copy()
{
	return new Karas(*this);
}
Karas::Karas(const Karas& obj) :Animals(obj)
{
	Name = obj.Name;
	Class = obj.Class;
	Volier = obj.Volier;
	Days = obj.Days;
}
