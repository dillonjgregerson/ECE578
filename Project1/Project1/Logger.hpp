///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
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