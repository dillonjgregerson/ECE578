///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Station.hpp"
#include "DcfProtocol.hpp"
#include "Simulator.hpp"
#include "AccessPoint.hpp"
#include "Message.hpp"
#include "PoissonDistribution.hpp"
#include "Math.h"

//Performance Metrics
//Throughput T: The individual station's throughput as a function of lambdaA
//Collisions N: The number of collisions (Data and RTS/CTS as a function of lambda
//Fairness Index FI: The fraction of time that the channel is occupied by a pair A->B
// over the fraction of time that the channel is occupied by pair CD as a fraciton of lambda

int main()
{
	Simulator simulator;

	std::cout << "Hello Simulation\n";
	Station::StationConfig stationAConfig;
	Station::StationConfig stationBConfig;

	stationAConfig.stationName = "Station A";
	stationAConfig.stationId   = simulator.getUniqueMsgId();
	stationAConfig.protocol    = new DcfProtocol(stationAConfig.stationId);

	Station stationA(stationAConfig);

	stationBConfig.stationName = "Station B";
	stationBConfig.stationId = simulator.getUniqueMsgId();
	stationBConfig.protocol = new DcfProtocol(stationBConfig.stationId);

	Station stationB(stationBConfig);


	AccessPoint::ConfigData config;
	config.protocol = new ProtocolBase();
	AccessPoint accessPoint(config);

	accessPoint.addReceptionStations(&stationA);
	accessPoint.addReceptionStations(&stationB);

	accessPoint.printReceptionStations();

	simulator.addStation(&stationA);
	simulator.addStation(&accessPoint);

	for (int i = 0; i < 70; i++)
	{
		simulator.update();
	}
}
