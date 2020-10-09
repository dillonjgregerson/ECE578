
#include "SimState.hpp"

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
void SimState::incrementSlot(void)
{
    currSlotTime_++;
}

long SimState::getSlotTime(void)
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