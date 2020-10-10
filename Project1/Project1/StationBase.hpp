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