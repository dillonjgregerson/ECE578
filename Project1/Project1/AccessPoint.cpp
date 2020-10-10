///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
#include "AccessPoint.hpp"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
// @brief Constructor
// @params const ConfigData& config: configuration data for access poitn
// @return void
///////////////////////////////////////////////////////////////////////////////
AccessPoint::AccessPoint(const ConfigData& config):
	StationBase(0),
	pSimState_(SimState::getInstance()),
	protocol_(config.protocol),
	ackMsg_(0),
	listeningInit_(false),
	recievingInit_(false),
	ackInit_(false),
	msgFrameIndex_(0),
	nextState_(LISTENING),
	currState_(LISTENING),
	receiveMsg_(config.msgId)
{
}

///////////////////////////////////////////////////////////////////////////////
// @brief Destructor
// @params void
// @return void
///////////////////////////////////////////////////////////////////////////////
AccessPoint::~AccessPoint(void)
{

}

///////////////////////////////////////////////////////////////////////////////
// @brief update the protocol
// @params void
// @return void
///////////////////////////////////////////////////////////////////////////////
void AccessPoint::update(void)
{
	pSimState_->getSignals();
}

///////////////////////////////////////////////////////////////////////////////
// @brief addReceptionStation: add stations it will listen for
// @params StationBase* station: the station it will listen to
// @return bool return true if station was successfully added
///////////////////////////////////////////////////////////////////////////////
bool AccessPoint::addReceptionStations(StationBase* station)
{
	receptionStations_.push_back(station);
	return true;
}

///////////////////////////////////////////////////////////////////////////////
// @brief printReceptionStations, prints all stations it is configured to listen
//        for
// @params void
// @return void
///////////////////////////////////////////////////////////////////////////////
void AccessPoint::printReceptionStations(void)const 
{
	std::cout << "Displaying all stations this AccessPoint is listening to :" << std::endl;

	for (auto const& a : receptionStations_)
	{
		std::cout << a->getStationName() << ": StationId: " << a->getStationId() << std::endl;
	}
}

///////////////////////////////////////////////////////////////////////////////
// @brief listen to the link and update it's state accordingly
// @params void
// @return void
///////////////////////////////////////////////////////////////////////////////
void AccessPoint::listen(void)
{
	unsigned long currSignal = pSimState_->getSignals();
	bool receive = false; //this means that it has heard the msgId sent out by one of the 
						  //stations it is configured to recieve
	switch (currState_)
	{
	case LISTENING:
		for (auto const& a : receptionStations_)
		{
			if (currSignal == a->getStationId())
			{
				receive = true;
				ackMsg_ = a->getStationId() + RANDOM_ACK_OFFSET;
			}
		}
		if (receive == true)
		{
			nextState_ = RECEIVING;
			receive = false;
			recievingInit_ = false;
		}
		break;
	case RECEIVING: 
		if (msgFrameIndex_ < receiveMsg_.msgFrameSize()-1)
		{
			receiveMsg_.frame_[msgFrameIndex_] = pSimState_->getSignals();
		}
		else
		{
			if (msgFrameIndex_ == receiveMsg_.msgFrameSize())
			{
				nextState_ = ACK;
			}
			else
			{
				nextState_ = LISTENING;
			}
		}
		break;

	case ACK: 
		break;

		currState_ = nextState_;
	}
}

///////////////////////////////////////////////////////////////////////////////
// @brief take action based on the chosen protocol
// @params void
// @return void
///////////////////////////////////////////////////////////////////////////////
void AccessPoint::takeAction(void)
{
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////