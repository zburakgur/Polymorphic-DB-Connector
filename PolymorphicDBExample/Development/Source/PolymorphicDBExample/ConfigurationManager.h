/****************************** Module Header ******************************\
* Module Name:  ConfigurationManager.cpp
*
* This module manages exe's configurations. Reads data from config.txt file
* in same location with exe. Config file format is;
* dbDllPath:
* dbAddress:
* dbName:
* dbUserName:
* dbPasswrd:
\***************************************************************************/

#pragma once

#include <fstream>
#include <string>
#include <map>

using namespace std;

// singleton
class ConfigurationManager
{
public:

	~ConfigurationManager(){ if (instance != nullptr)	delete instance; };

	static ConfigurationManager * getInstance();
	void read();
	string getConfigValue(string config);

private:

	ConfigurationManager(){ path = "config.txt"; }
	static ConfigurationManager * instance;

	// config values holds in map with same tag names of the config file 
	map<string, string> configs;
	ifstream reader;
	string path;
};

