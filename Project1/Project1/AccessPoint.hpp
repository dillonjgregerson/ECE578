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
private:
	AccessPoint(void);
};