///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
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
