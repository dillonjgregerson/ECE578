///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>

class StationBase
{
public:
	explicit StationBase(unsigned long stationId);
	virtual ~StationBase(void);
	virtual std::string getStationName(void) const;
	virtual long getStationId(void) const;
	virtual void listen(void);
	virtual void takeAction(void);

	std::string stationName_;
	unsigned long stationId_;
protected:
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////