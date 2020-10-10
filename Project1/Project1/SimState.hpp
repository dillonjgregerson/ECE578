#pragma once

#include "Message.hpp"

class SimState
{
public:
	SimState(void);
	~SimState(void);
	void updateSlot(void); //this will increment the current slot, and in return , reset the signals to 0;
	unsigned long getSlotTime(void);
	static SimState* getInstance(void);
	unsigned long getSignals(void);
	void updateState(unsigned long currSignal);
	bool generatePoissonProcess(void);
protected:
	static SimState instance_;
	static SimState* pInstance_;

	long currSlotTime_;
	long currSignals_; //this represents the current state of the airwaves.

};