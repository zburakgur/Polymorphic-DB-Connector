#include "stdafx.h"
#include "ConfigurationManager.h"
#include "Functions.h"

void ConfigurationManager::read()
{
	string configPath = Functions::exePath();
	configPath.append("\\" + path);

	reader.open(configPath);
	if (!reader.is_open()) throw NotFoundException(path, "Config file is not found");

	while (reader)
	{
		string line;
		getline(reader, line);

		string values[2];
		Functions::split(line, ':', values, 2);

		configs[values[0]] = values[1];
	}

	reader.close();
}

string ConfigurationManager::getConfigValue(string config)
{
	auto it = configs.find(config);

	if (it == configs.end())	throw NotFoundException(config, "Config value is not found in config file");
	else return it->second;
}

ConfigurationManager * ConfigurationManager::instance = nullptr;
ConfigurationManager * ConfigurationManager::getInstance()
{
	if (instance == nullptr)
		instance = new ConfigurationManager();
	return instance;
}