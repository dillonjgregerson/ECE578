#include <iostream>
#include <cstdlib>
#include "Simulator.hpp"

Simulator::Simulator(void):
	simState_(SimState::getInstance())
{

}

Simulator::~Simulator(void)
{
    
}

void Simulator::update(void)
{
	simState_->updateSlot();
	for (auto const& a : stations_)
	{
		a->listen();
	}

	for (auto const& a : stations_)
	{
		a->takeAction();
	}

	std::cout << "Current Slot Time: " << simState_->getSlotTime() << std::endl;

}

bool Simulator::addStation(StationBase* station)
{
	stations_.push_back(station);
	return true;
}

unsigned long Simulator::getUniqueMsgId(void) const
{
	long newMsgId = 0;
	bool unique   = false;
	do
	{
		unique = true;
		newMsgId = rand() % 10000000;
		for (auto const& a : stations_)
		{
			if (newMsgId == a->getStationId())
			{
				unique = false;
			}
		}
	} while (!unique);

	return newMsgId;
}