#include <iostream>
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
	for (auto const& a : stations_)
	{
		std::cout << a->getStationName() << std::endl;
	}
}

bool Simulator::addStation(Station* station)
{
	stations_.push_back(station);
	return true;
}