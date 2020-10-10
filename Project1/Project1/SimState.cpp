
#include "SimState.hpp"
#include <cstdlib>

SimState SimState::instance_;
SimState* SimState::pInstance_(0);

SimState::SimState(void):
	currSlotTime_(0)
{

}

SimState::~SimState(void)
{
    //deallocate
}
void SimState::updateSlot(void)
{
    currSlotTime_++;
	currSignals_ = 0;
}

unsigned long SimState::getSlotTime(void)
{
    return currSlotTime_;
}

SimState* SimState::getInstance(void)
{
	if (pInstance_ == 0)
	{
		pInstance_ = &instance_;
	}
	return pInstance_;
}

unsigned long SimState::getSignals(void)
{
	return currSignals_;
}

void SimState::updateState(unsigned long currSignal)
{
	currSignals_ += currSignal;
}

bool SimState::generatePoissonProcess(void)
{
	//this function will determine whether or not a station wants to send a message;
	//todo fill in with actual PoissonProcess formula
	bool retVal;
	if (rand() % 10 > 5)
	{
		retVal = false;
	}
	else
	{
		retVal = true;
	}
	return retVal;
}