// DLL.cpp : Определяет экспортируемые функции для DLL.
//

#include "framework.h"
#include "DLL.h"
#include<fstream>
#include <time.h>

// Пример экспортированной переменной
DLL_API int nDLL=0;

// Пример экспортированной функции.
DLL_API int fnDLL(void)
{
    return 0;
}

// Конструктор для экспортированного класса.
CDLL::CDLL()
{
    return;
}
DB db;
void DLL_API Create()
{
    db.Set_Vec();
}
BSTR DLL_API Get_Name(int index)
{
    return _com_util::ConvertStringToBSTR(db.Get_Vec()[index]->Get_Name().c_str());
}
BSTR DLL_API Get_Volier(int index)
{
    return _com_util::ConvertStringToBSTR(db.Get_Vec()[index]->Get_Volier().c_str());
}
BSTR DLL_API Get_Class(int index)
{
    return _com_util::ConvertStringToBSTR(db.Get_Vec()[index]->Get_Class().c_str());
}
BSTR DLL_API Get_Days(int index)
{
    return _com_util::ConvertStringToBSTR(db.Get_Vec()[index]->Get_Days().c_str());
}
int DLL_API Get_Size()
{
    return db.Get_Vec().size();
}
void DLL_API Sort_Name()
{
    db.Sort_Name();
}
void DLL_API Sort_Volier()
{
    db.Sort_Volier();
}
void DLL_API Sort_Class()
{
    db.Sort_Class();
}
bool DLL_API Proverka_Na_Den(int index, BSTR stroka)
{
    return  db.Get_Vec()[index]->Proverka_Na_Den(stroka);
}
BSTR DLL_API Animals_V_Day(BSTR Incl_Days)
{   
    vector<int> Result{ 1,2,3,4,5,6,7 };
    string Vihod;
    char* s  = _com_util::ConvertBSTRToString(Incl_Days);
    string stroka = s;
    for (int i = 0; i < stroka.size(); i++)
    {
        db.Get_Vec()[stroka[i] - '0']->Days_Dly_Zapisi(Result);
    }
    for (int i = 0; i < Result.size(); i++)
    {
        Vihod += to_string(Result[i]);
    }
    delete s;
    return _com_util::ConvertStringToBSTR(Vihod.c_str());
}
void Zapis_v_file(BSTR stroka)
{
    char* s = _com_util::ConvertBSTRToString(stroka);
    string Old;
    fstream file;
    file.open("../Экскурсии.txt");
    string infile;
    for (;;)
    {
        getline(file, infile);
        if (file.eof())
        {
            infile.clear();
            break;
        }
        Old = Old + infile + "\n";
    }
    file.close();
    Old += s;
    file.open("../Экскурсии.txt");
    file << Old;
    file.close();
    Old.clear();
    delete s;
    infile.clear();
}
BSTR DLL_API Cluchainay_Exckyrsiy()
{
    int start = 1;
    int end = db.Get_Vec().size() - 1;
    srand(time(NULL));
    int x = rand() % (db.Get_Vec().size() - 2)+1;
    vector<int> Vector;
    for (int i = 0; i < db.Get_Vec().size(); i++)
    {
        Vector.push_back(i);
    }
    pair<vector<int>::iterator, vector<int>::iterator> result_bound = equal_range(Vector.begin(), Vector.end(),x);//equal_range
    string s = to_string(*result_bound.first);
    s = s + to_string(*result_bound.second);
    
    return _com_util::ConvertStringToBSTR(s.c_str());
}
void DLL_API Zapis_v_file_obchie(BSTR stroka)
{
    char* s = _com_util::ConvertBSTRToString(stroka);  
    string Old;
    fstream file;
    file.open("../ОбщиеЭкскурсии.txt");
    string infile;
    for (;;)
    {
        getline(file, infile);
        if (file.eof())
        {
            infile.clear();
            break;
        }
        Old = Old + infile + "\n";
    }
    file.close(); 
    Old += s;
    file.open("../ОбщиеЭкскурсии.txt");
    file << Old;
    file.close();
    Old.clear();
    delete s;
    infile.clear();
}

DLL_API LONG_PTR Memory(wchar_t**& ppNames)

{
   /* HANDLE hLogFile;

    hLogFile = File(L"log.txt", GENERIC_WRITE,

        FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,

        FILE_ATTRIBUTE_NORMAL, NULL);

    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);

    _CrtSetReportFile(_CRT_WARN, hLogFile);

    _CrtDumpMemoryLeaks();

    CloseHandle(hLogFile);

    vector <string> n;

    string v((std::istreambuf_iterator<char>(*(std::unique_ptr<std::ifstream>(new std::ifstream("log.txt"))).get())), std::istreambuf_iterator<char>());

    n.push_back(v);

    LONG_PTR newStringsArraySize = 0;

    {

        CoTaskMemFree(ppNames);

        ppNames = NULL;

        newStringsArraySize = n.size();

        LONG_PTR newwidth = 0;

        wchar_t** newArray = (wchar_t**)CoTaskMemAlloc(sizeof(wchar_t*) * newStringsArraySize);

        for (LONG_PTR j = 0; j < newStringsArraySize; j++)

        {

            wstring wstr1(n[j].begin(), n[j].end());

            newwidth = wstr1.size() + 1;

            newArray[j] = (wchar_t*)CoTaskMemAlloc(sizeof(wchar_t) * newwidth);

            ::ZeroMemory(newArray[j], sizeof(wchar_t) * newwidth);

            swprintf(newArray[j], newwidth, wstr1.data());

        }

        ppNames = newArray;

    }
    */
    return 1;

}
DLL_API void Distructor()
{
    db.~DB();
}
int* x = new int; // проверка на утечки - 4 байта