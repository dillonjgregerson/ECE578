#include "Station.hpp"
#include <string>

Station::Station(const std::string stationName):
	currentSlot_(0),
	stationName_(stationName)
{

}

Station::~Station(void)
{
	//deallocate
}

std::string Station::getStationName(void) const
{
	return stationName_;
}