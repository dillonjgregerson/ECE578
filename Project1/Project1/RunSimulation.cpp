#include "Station.hpp"
#include <iostream>
#include "DcfProtocol.hpp"
#include "Simulator.hpp"

//Performance Metrics
//Throughput T: The individual station's throughput as a function of lambdaA
//Collisions N: The number of collisions (Data and RTS/CTS as a function of lambda
//Fairness Index FI: The fraction of time that the channel is occupied by a pair A->B
// over the fraction of time that the channel is occupied by pair CD as a fraciton of lambda

int main()
{
	std::cout << "Hello Simulation\n";
	Station::StationConfig stationAConfig;
	Station::StationConfig stationBConfig;

	stationAConfig.protocol = new DcfProtocol();
	stationAConfig.stationName = "Station A";

	stationBConfig.protocol = new ProtocolBase();
	stationBConfig.stationName = "Station B";

	Station stationA(stationAConfig);
	Station stationB(stationBConfig);

	Simulator simulator;
	simulator.addStation(&stationA);
	simulator.addStation(&stationB);
	simulator.update();
}
