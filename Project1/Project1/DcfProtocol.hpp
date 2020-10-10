#pragma once

#include "ProtocolBase.hpp"
#include "SimState.hpp"
#include "Message.hpp"

class DcfProtocol: public ProtocolBase
{
	using ProtocolBase::execute;

	struct Interval
	{
		int startTime;
		int endTime;
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


};