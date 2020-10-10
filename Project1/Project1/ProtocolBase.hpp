///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
#pragma once

class ProtocolBase
{
public:
	ProtocolBase();
	virtual ~ProtocolBase();
	virtual void nextAction(void);
	virtual void execute(void);
	void updateState(unsigned long signal, unsigned long currSlot);
	unsigned long currSignal_;
	unsigned long currSlot_;
};