#include <string>
#include <cstdlib>
#include "Station.hpp"
#include "ProtocolBase.hpp"

Station::Station(const StationConfig& config):
	protocol_(config.protocol),
	stationName_(config.stationName),
	currentSlot_(0)
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

int Station::getId(void) const
{
	return stationId_;
}

void Station::initialize(int id)
{
	//do station Initialization
}

int Station::selectBackoff(void)
{
	return rand() % SimParamsT::CW0;
}

void Station::update(void)
{
	protocol_->execute();
}