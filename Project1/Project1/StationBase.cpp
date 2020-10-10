
#include "StationBase.hpp"


StationBase::StationBase(unsigned long stationId):stationId_(stationId)
{

}

StationBase::~StationBase(void)
{

}

std::string StationBase::getStationName(void) const
{
	return stationName_;
}

long StationBase::getStationId(void) const
{
	return stationId_;
}

void StationBase::listen(void)
{

}

void StationBase::takeAction(void)
{
}