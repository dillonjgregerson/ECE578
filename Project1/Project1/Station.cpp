
#include <string>
#include <cstdlib>
#include "Station.hpp"
#include "ProtocolBase.hpp"

Station::Station(const StationConfig& config):
	StationBase(config.stationId),
	protocol_(config.protocol),
	stationName_(config.stationName),
	currentSlot_(0),
	pSimState_(SimState::getInstance())
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

void Station::listen(void)
{
	protocol_->updateState(pSimState_->getSignals(), pSimState_->getSlotTime());
}

void Station::takeAction(void)
{
	protocol_->execute();
}
