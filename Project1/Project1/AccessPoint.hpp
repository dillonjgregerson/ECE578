///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <list>
#include "ProtocolBase.hpp"
#include "SimParamsT.hpp"
#include "SimState.hpp"
#include "StationBase.hpp"

class AccessPoint: public StationBase
{
	using StationBase::stationName_;
	enum AccessPointState
	{
		LISTENING,
		RECEIVING,
		ACK
	};

public:
	struct ConfigData
	{
		ProtocolBase* protocol;
		std::string accessPointName;
		long msgId;
	};

	explicit AccessPoint(const ConfigData& config);
	virtual ~AccessPoint(void);
	void update(void);
	void listen(void);
	void takeAction(void);
	bool addReceptionStations(StationBase *station);
	void printReceptionStations(void) const;
protected:
	std::list<StationBase*> receptionStations_;
	ProtocolBase* protocol_;
	SimState* pSimState_;
	Message receiveMsg_;
	AccessPointState currState_;
	AccessPointState nextState_;
	unsigned long ackMsg_;
	bool listeningInit_;
	bool recievingInit_;
	bool ackInit_;
	unsigned int msgFrameIndex_;
	const static unsigned long RANDOM_ACK_OFFSET = 14257;

private:
	AccessPoint(void);
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////