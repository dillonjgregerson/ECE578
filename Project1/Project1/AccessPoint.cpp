
#include "AccessPoint.hpp"
#include <iostream>

AccessPoint::AccessPoint(const ConfigData& config):
	StationBase(0),
	pSimState_(SimState::getInstance()),
	protocol_(config.protocol)
{

}

AccessPoint::~AccessPoint(void)
{

}

void AccessPoint::update(void)
{
	pSimState_->getSignals();
}

bool AccessPoint::addReceptionStations(StationBase* station)
{
	receptionStations_.push_back(station);
	return true;
}

void AccessPoint::printReceptionStations(void)const 
{
	std::cout << "Displaying all stations this AccessPoint is listening to :" << std::endl;

	for (auto const& a : receptionStations_)
	{
		std::cout << a->getStationName() << ": StationId: " << a->getStationId() << std::endl;
	}
}

void AccessPoint::listen(void)
{
	unsigned long currSignal = pSimState_->getSignals();
	bool recieve = false;
	for(auto const& a: receptionStations_)
	{

	}
	std::cout << "AccessPoint is listening\n";
}

void AccessPoint::takeAction(void)
{
	std::cout << "AccessPoint is taking action\n";
}