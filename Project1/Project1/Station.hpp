#pragma once

#include "StationBase.hpp"
#include <string>

class Station : public StationBase
{
	enum State
	{
		DEFAULT = 0
		//todo fill in
	};

public:
	Station(const std::string stationName);
	~Station(void);
	std::string getStationName(void) const;
protected:
	long currentSlot_;
	std::string stationName_;


};