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

	//Configuring and setting up Station A
	Station::StationConfig stationAConfig;
	stationAConfig.stationName = "Station A";
	stationAConfig.stationId   = simulator.getUniqueMsgId();
	stationAConfig.protocol    = new DcfProtocol(stationAConfig.stationId);
	Station stationA(stationAConfig);

	//Configuring and setting up Access Point B
	AccessPoint::ConfigData configApB;
	configApB.msgId = simulator.getUniqueMsgId();
	configApB.accessPointName = "Access Point B";
	configApB.protocol = new DcfProtocol(configApB.msgId);
	AccessPoint accessPointB(configApB);
	accessPointB.addReceptionStations(&stationA);
	accessPointB.printReceptionStations();

	//Adding Station A and Access Point B to the Simulator
	simulator.addStation(&stationA);
	simulator.addStation(&accessPointB);


	///////////////////////////////////////////////////////////////////
	//Configuring and setting up Station C
	Station::StationConfig stationCConfig;
	stationCConfig.stationName = "Station C";
	stationCConfig.stationId = simulator.getUniqueMsgId();
	stationCConfig.protocol = new DcfProtocol(stationCConfig.stationId);
	Station stationC(stationCConfig);

	//Configuring and setting up Access Point D
	AccessPoint::ConfigData configApD;
	configApD.msgId = simulator.getUniqueMsgId();
	configApD.accessPointName = "Access Point B";
	configApD.protocol = new DcfProtocol(configApD.msgId);
	AccessPoint accessPointD(configApD);
	accessPointB.addReceptionStations(&stationC);
	accessPointB.printReceptionStations();

	//Adding Station A and Access Point B to the Simulator
	simulator.addStation(&stationC);
	simulator.addStation(&accessPointD);

	for (int i = 0; i < 10000; i++)
	{
		simulator.update();
	}

std::cout << "Total number of msgs received: " <<  accessPointB.getNumMsgsReceived() << std::endl;
}
