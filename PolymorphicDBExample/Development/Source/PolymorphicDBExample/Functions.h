/****************************** Module Header ******************************\
* Module Name:  Functions.cpp
*
* This module includes utulity functions and exceptions.
\***************************************************************************/

#pragma once

#include <Windows.h>
#include <string>
#include <io.h>
#include <sstream>

using namespace std;

class Functions
{
public:
	
	static bool checkFileExist(string & path);
	static int split(string & txt, char delimeter, string[], int size);
	static wstring stringToWString(const std::string& s);
	static void logService(const string & method, const string & msg);
	static string exePath();
	static string getCurrDateString();
	static string getCurrDateTimeString();
};

class NotFoundException
{
private:

	string item;
	string msg;
public:

	NotFoundException(const string &item, const string &msg) :item(item), msg(msg){};
	string getMsg() const;
};