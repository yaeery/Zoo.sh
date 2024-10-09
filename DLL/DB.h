#pragma once
#include"Animals.h"
#include"Karas.h"
#include"Limur.h"
#include"Koala.h"
#include"Nosorog.h"
#include"Pingvin.h"
#include"Zhiraf.h"
#include"Kapibara.h"
class DLL_API DB
{
	vector<Animals*> Vec;
public:
	vector<Animals*> Get_Vec();
	void Set_Vec();
	DB();
	~DB();
	void Sort_Name();
	void Sort_Volier();
	void Sort_Class();
	DB(const DB& obj);
	DB* Copy();
};

