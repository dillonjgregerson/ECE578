///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <cstdlib>
#include <Math.h>
#include <ctime>
#include <iostream>

template<int NUM_FRAMES_PER_SECOND>
class PoissonDistribution
{
	static const int NUM_SECONDS = 10;
	static const int NUM_FRAMES = NUM_SECONDS * NUM_FRAMES_PER_SECOND;

public:
	float arrayInterArrival_[NUM_FRAMES];
	float arrayInterArrivalSlots_[NUM_FRAMES];
	int nextSlotArrivalIndex_;
	PoissonDistribution(void):nextSlotArrivalIndex_(0)
	{
		memset(static_cast<void*>(arrayInterArrival_), 0, sizeof(arrayInterArrival_));
		memset(static_cast<void*>(arrayInterArrivalSlots_), 0, sizeof(arrayInterArrivalSlots_));
	}
	~PoissonDistribution(void) {}
	void generateDistribution(void)
	{
		srand((unsigned int)time(NULL));
		for (int i = 0; i < NUM_FRAMES - 1; i++)
		{
			float randFloat = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			float tempVal = -1.0f / static_cast<float>(NUM_FRAMES_PER_SECOND);
			arrayInterArrival_[i] = tempVal * log(1-randFloat);
			arrayInterArrivalSlots_[i] = static_cast<int>(arrayInterArrival_[i]/0.00001); //diving by the slot lenth (10 mus)
		}
	}

	unsigned int getNextSlotArrival(void)
	{
		unsigned int retVal = arrayInterArrivalSlots_[nextSlotArrivalIndex_];
		nextSlotArrivalIndex_++;
		return retVal;
	}
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////