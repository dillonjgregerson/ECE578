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
	void initialize(int id);
	int getId(void) const;

protected:
	ProtocolBase *protocol_;
	SimState *pSimState_;
	long currentSlot_;
	std::string stationName_;
};