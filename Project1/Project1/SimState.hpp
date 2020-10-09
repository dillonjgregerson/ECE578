#pragma once

class SimState
{
public:
	SimState(void);
	~SimState(void);
	void incrementSlot(void);
	long getSlotTime(void);
	static SimState* getInstance(void);
protected:
	static SimState instance_;
	static SimState* pInstance_;

	long currSlotTime_;
};