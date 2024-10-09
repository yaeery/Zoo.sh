#include "DB.h"
DB::DB(){}
DB::~DB()
{
	for (int i = 0; i < Vec.size(); i++)
	{
		delete Vec[i];
	}
}

vector<Animals*> DB::Get_Vec()
{
	return Vec;
}
void DB::Set_Vec()
{
	Vec.push_back(new Kapibara());
	Vec.push_back(new Koala());
	Vec.push_back(new Karas());
	Vec.push_back(new Nosorog());
	Vec.push_back(new Limur());
	Vec.push_back(new Pingvin());
	Vec.push_back(new Zhiraf());
}
void DB::Sort_Name()
{
	sort(Vec.begin(), Vec.end(), [](Animals* first, Animals* second) {return first->Get_Name() < second->Get_Name(); }); //первый алгоритм 
}
void DB::Sort_Volier()
{
	sort(Vec.begin(), Vec.end(), [](Animals* first, Animals* second) {return stoi(first->Get_Volier()) < stoi(second->Get_Volier()); }); 
}
void DB::Sort_Class()
{
	sort(Vec.begin(), Vec.end(), [](Animals* first, Animals* second) {return first->Get_Class() < second->Get_Class(); });
}
DB::DB(const DB& obj)
{
	for (int i = 0; i < Vec.size(); i++)
	{
		Vec.push_back(obj.Vec[i]->Copy());
	}
}
 DB* DB::Copy()
 {
	 return new DB(*this);
 }
