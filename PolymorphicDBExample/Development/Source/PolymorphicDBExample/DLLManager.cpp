#include "stdafx.h"
#include "DLLManager.h"
#include "ConfigurationManager.h"
#include "Functions.h"

void DBAPI::load(string & dllpath, string & getApiFunc)
{
	hGetProcIdDLL = LoadLibraryA(dllpath.c_str());

	GETLISTFUNC lpGetApis = (GETLISTFUNC)GetProcAddress(hGetProcIdDLL, getApiFunc.c_str());
	if (!lpGetApis)	throw NotFoundException(dllpath, "Dll is not found on the path");

	apis = lpGetApis();
}

void DBAPI::free()
{
	FreeLibrary(hGetProcIdDLL);
}

PDbBaseConnection * DBAPI::getConnObj()
{
	PDbBaseObject * ptrTmp = apis->conn->clone();
	return dynamic_cast<PDbBaseConnection *>(ptrTmp);
}

PDbBaseQuery * DBAPI::getQueryObj()
{
	PDbBaseObject * ptrTmp = apis->query->clone();
	return dynamic_cast<PDbBaseQuery *>(ptrTmp);
}

DBAPI * DBAPI::instance = nullptr;
DBAPI * DBAPI::getInstance()
{
	if (instance == nullptr)
		instance = new DBAPI();
	return instance;
}