#include "stdafx.h"
#include "Functions.h"
#include <fstream>
#include <ctime>

bool Functions::checkFileExist(string & path)
{
	bool result = true;
	if (_access(path.c_str(), 0) == -1)	result = false;
	
	return result;
}

int Functions::split(string & txt, char delimeter, string arr[], int size)
{
	istringstream stream(txt);
	string token;
	
	int i = 0;

	while (getline(stream, token, delimeter))
	{
		if (i >= size)	break;
		arr[i] = token;

		i++;
	}

	return i;
}

void Functions::logService(const string & folderName, const string & msg)
{
	string path = exePath();
	string now = getCurrDateString();
	path += "\\..\\logs\\" + folderName;
		
	if (CreateDirectory(stringToWString(path).c_str(), NULL) ||
	ERROR_ALREADY_EXISTS == GetLastError())
	{
		path += "\\" + now + ".txt";;
		ofstream file;
		file.open(path, std::ofstream::out | std::ofstream::app);

		if (file)
		{
			string log = Functions::getCurrDateTimeString() + " : " + msg + "\n";
			file << log;
			file.close();
		}
	}
}

string Functions::getCurrDateString()
{
	time_t currentTime = time(0);
	tm * now = localtime(&currentTime);

	int year = now->tm_year + 1900;
	int month = now->tm_mon + 1;
	int day = now->tm_mday;

	string result = to_string(year);
	
	if (month < 10)	result.append("0" + to_string(month));
	else			result.append(to_string(month));

	if (day < 10)	result.append("0" + to_string(day));
	else			result.append(to_string(day));

	return result;
}

string Functions::getCurrDateTimeString()
{
	time_t currentTime = time(0);
	tm * now = localtime(&currentTime);

	int year = now->tm_year + 1900;
	int month = now->tm_mon + 1;
	int day = now->tm_mday;
	int hour = now->tm_hour;
	int min = now->tm_min;
	int sec = now->tm_sec;

	string result = to_string(year);

	if (month < 10)	result.append("0" + to_string(month));
	else			result.append(to_string(month));

	if (day < 10)	result.append("0" + to_string(day));
	else			result.append(to_string(day));
	
	if (hour < 10)	result.append("0" + to_string(hour));
	else			result.append(to_string(hour));

	if (min < 10)	result.append("0" + to_string(min));
	else			result.append(to_string(min));

	if (sec < 10)	result.append("0" + to_string(sec));
	else			result.append(to_string(sec));

	return result;
}

string Functions::exePath() {
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

wstring Functions::stringToWString(const string& s)
{
	std::wstring temp(s.length(), L' ');
	std::copy(s.begin(), s.end(), temp.begin());
	return temp;
}

string NotFoundException::getMsg() const
{
	return string("'" + item + "' " + msg);
}
