///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Message.hpp"
#include "PoissonDistribution.hpp"

class SimState
{
public:
	SimState(void);
	~SimState(void);
	void updateSlot(void); //this will increment the current slot, and in return , reset the signals to 0;
	unsigned long getSlotTime(void);
	static SimState* getInstance(void);
	unsigned long getSignals(void);
	void sendSignals(unsigned long currSignal);
	unsigned int getNextArrivalSlot(void);
	void clearSignals(void);

protected:
	static SimState instance_;
	static SimState* pInstance_;
	PoissonDistribution <200>poissonDistribution_;

	long currSlotTime_;
	long currSignals_; //this represents the current state of the airwaves.

};