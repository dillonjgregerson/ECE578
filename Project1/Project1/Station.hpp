///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include "SimParamsT.hpp"
#include "ProtocolBase.hpp"
#include "StationBase.hpp"
#include "SimState.hpp"

class Station: public StationBase
{
	enum State
	{
		DEFAULT = 0
		//todo fill in
	};
	struct location
	{
		int x;
		int y;
	};
public:
	struct StationConfig
	{
		std::string stationName;
		ProtocolBase *protocol;
		unsigned long stationId;
	};

	Station(const StationConfig& config);
	virtual ~Station(void);
	std::string getStationName(void) const;
	void listen(void);
	void takeAction(void);
	void initialize(unsigned long);
	unsigned long getId(void) const;

protected:
	ProtocolBase *protocol_;
	SimState *pSimState_;
	long currentSlot_;
	std::string stationName_;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////