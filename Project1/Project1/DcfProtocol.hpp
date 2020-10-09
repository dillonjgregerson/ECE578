#pragma once

#include "ProtocolBase.hpp"

class DcfProtocol: public ProtocolBase
{
	using ProtocolBase::execute;
public:
	DcfProtocol(void);
	~DcfProtocol(void);
	enum DcfState
	{
		DIFS = 0,
		BACKOFF,
		HDR,
		FRAME,
		SIFS,
		ACK,
		NUM_STATES
	};
	DcfState currState_;
	void execute(void);

};