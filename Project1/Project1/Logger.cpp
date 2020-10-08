#include "Logger.hpp"

Logger::Logger(std::string fileName, std::ofstream thisFile):
	fileName_(fileName),
	thisFile_(thisFile)
{
	// do initializations
}

Logger::~Logger(void)
{
	//deallocation
}

void Logger::write(int data)
{
	thisFile_.open(fileName_);
	thisFile_ << "," << data;
	thisFile_.close();
}

void Logger::write(float data)
{
	thisFile_.open(fileName_);
	thisFile_ << "," << data;
	thisFile_.close();
}
