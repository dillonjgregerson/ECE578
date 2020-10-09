#pragma once

#include <string>
#include "SimParamsT.hpp"
#include "ProtocolBase.hpp"

class Station
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

	};
	Station(const StationConfig& config);
	~Station(void);
	std::string getStationName(void) const;
	void update(void);
	void initialize(int id);
	int getId(void) const;
	int stationId_;
	int backoff_;
protected:
	ProtocolBase *protocol_;

	long currentSlot_;
	std::string stationName_;
	int selectBackoff(void);
	
};