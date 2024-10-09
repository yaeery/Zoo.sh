// Приведенный ниже блок ifdef — это стандартный метод создания макросов, упрощающий процедуру
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа DLL_EXPORTS
// Символ, определенный в командной строке. Этот символ не должен быть определен в каком-либо проекте,
// использующем данную DLL. Благодаря этому любой другой проект, исходные файлы которого включают данный файл, видит
// функции DLL_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#include"DB.h"
// Этот класс экспортирован из библиотеки DLL
class DLL_API CDLL {
public:
	CDLL(void);
	// TODO: добавьте сюда свои методы.
};

extern DLL_API int nDLL;

DLL_API int fnDLL(void);
extern "C"
{
	void DLL_API Create();
	BSTR DLL_API Get_Name(int index);
	BSTR DLL_API Get_Volier(int index);
	BSTR DLL_API Get_Class(int index);
	BSTR DLL_API Get_Days(int index);
	int DLL_API Get_Size();
	void DLL_API Sort_Name();
	void DLL_API Sort_Volier();
	void DLL_API Sort_Class();
	bool DLL_API Proverka_Na_Den(int index, BSTR stroka);
	BSTR DLL_API Animals_V_Day(BSTR Incl_Days);
	void DLL_API  Zapis_v_file(BSTR stroka);
	BSTR DLL_API Cluchainay_Exckyrsiy();
	void DLL_API Zapis_v_file_obchie(BSTR stroka);
	DLL_API LONG_PTR Memory(wchar_t**& ppNames);
	DLL_API void Distructor();
}
