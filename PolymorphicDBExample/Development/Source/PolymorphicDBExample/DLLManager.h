/****************************** Module Header ******************************\
* Module Name:  DLLManager.cpp
*
* This module serves to load and free dynamic libraries to he service. In addition,
* dll classes and iinterfaces are presented in this header. LoadLibraryA func 
* is used to load dll, so ascii formation is used as text encoding
\***************************************************************************/

#pragma once

#include <vector>
#include <Windows.h>
#include "../PolymorphicDBConnector/PolymorphicDBConnector.h"

using namespace std;
using namespace PDb;

// singelton
class DBAPI
{
public:
	
	~DBAPI(){ if (instance != nullptr)	delete instance; };

	void load(string &, string &);
	void free();

	PDbBaseConnection * getConnObj();
	PDbBaseQuery * getQueryObj();

	static DBAPI * getInstance();

private:
	DBAPI(){};
	static DBAPI * instance;

	PDbObjects * apis = NULL;
	HINSTANCE hGetProcIdDLL = NULL;

	/* decleration of register fucntion of db dll */
	typedef PDbObjects *(*GETLISTFUNC)(void);
};

