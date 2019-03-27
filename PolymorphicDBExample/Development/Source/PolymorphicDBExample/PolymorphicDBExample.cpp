// PolymorphicDBExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConfigurationManager.h"
#include "DLLManager.h"
#include "Functions.h"
#include <iostream>

using namespace std;
using namespace PDb;

int main()
{
	try
	{
		ConfigurationManager* pCManager = ConfigurationManager::getInstance();
		pCManager->read();
		
		string dbDllPath = pCManager->getConfigValue("dbDllPath");
		string getApiFunc = "getRecordedObjects";

		DBAPI* pDbApi = DBAPI::getInstance();
		pDbApi->load(dbDllPath, getApiFunc);

		//database configurations
		PDbBaseConnection* pDbConn = pDbApi->getConnObj();
		PDbBaseQuery* pDbQuery = pDbApi->getQueryObj();

		pDbConn->setConnString(
			pCManager->getConfigValue("dbAddress"),
			pCManager->getConfigValue("dbName"),
			pCManager->getConfigValue("dbUserName"),
			pCManager->getConfigValue("dbPasswrd")
			);
		pDbQuery->setConn(pDbConn);

		pDbConn->connect();
		/*
		pDbQuery->clear();
		pDbQuery->addSQL("INSERT INTO PRODUCTS (PRODUCTNAME, PRODUCTCODE, PRICE, INSERTDATE) ");
		pDbQuery->addSQL("VALUES (?, ?, ?, ?) ");
		pDbQuery->addParam("PRODUCTNAME", ptVarChar)->setValue("LAPTOP");
		pDbQuery->addParam("PRODUCTCODE", ptInteger)->setValue(12345);
		pDbQuery->addParam("PRICE", ptDouble)->setValue(1234.56);
		pDbQuery->addParam("INSERTDATE", ptDateTime)->setValue("2019-03-27 12:27");
		pDbQuery->executeNonQuery();

		pDbConn->disconnect();
		*/
	}
	catch (NotFoundException &ex)
	{
		cout << ex.getMsg() << endl;
	}

	getchar();
	return 0;
}

