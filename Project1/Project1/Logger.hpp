#pragma once

#include <fstream>
#include <string>

class Logger
{
	std::string fileName_;
	std::ofstream& thisFile_;
	
	Logger(std::string fileLoc, std::ofstream thisFile);
	~Logger(void);
	void write(int var);
	void write(float var);
};