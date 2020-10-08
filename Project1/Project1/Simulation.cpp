#include "Station.hpp"
#include <iostream>

int main()
{
	std::cout << "Hello Simulation\n";
	Station stationA("StationA");
	Station stationB("StationB");

	std::cout << stationA.getStationName() << std::endl;
	std::cout << stationB.getStationName() << std::endl;
}