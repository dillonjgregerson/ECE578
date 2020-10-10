///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "ProtocolBase.hpp"
#include "SimState.hpp"
#include "Message.hpp"

class DcfProtocol: public ProtocolBase
{
	using ProtocolBase::execute;

	struct Interval
	{
		unsigned int startTime;
		unsigned int endTime;
		bool init;
	};

	Interval difs_;
	Interval collision_;
	Interval backoff_;
	Interval sifs_;
	Interval ack_;
	Interval idle_;
	Interval header_;
	Interval frame_;
	bool collisionOccurred_;
	bool backoffInterrupted_;

public:
	explicit DcfProtocol(unsigned long msgId);
	~DcfProtocol(void);
	enum DcfState
	{
		IDLE = 0,
		DIFS,
		BACKOFF,
		HDR,
		FRAME,
		SIFS,
		ACK,
		COLLISION,
		NUM_STATES
	};
	void printCurrState(void)const;
	DcfState currState_;
	DcfState nextState_;
	SimState* pSimState_;
	void execute(void);
	int getNewBackoff(void);
	unsigned long msgId_;
	bool ackRecieved_;
	bool linkBusy_;
	Message* pMessage_;
	int backoffTime_;
	unsigned long ackSignal_;
	const static unsigned long RANDOM_ACK_OFFSET = 14257;


};