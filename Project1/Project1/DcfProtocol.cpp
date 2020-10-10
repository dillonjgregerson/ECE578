///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <cstdlib>
#include "SimParamsT.hpp"
#include "DcfProtocol.hpp"

///////////////////////////////////////////////////////////////////////////////
// @brief Constructor
// @params unsigned long msgId
// @return void
///////////////////////////////////////////////////////////////////////////////
DcfProtocol::DcfProtocol(unsigned long msgId) :
	ProtocolBase(),
    pSimState_(SimState::getInstance()),
	msgId_(msgId),
	backoffInterrupted_(false),
	pMessage_(0)
{
	currState_ = IDLE;
	difs_.startTime = 0;
	difs_.endTime = 0;

	collision_.startTime = 0;
	collision_.endTime = 0;
	
	backoff_.startTime = 0;
	backoff_.endTime = 0;
	
	sifs_.startTime = 0;
	sifs_.endTime = 0;
	
	ack_.startTime = 0;
	ack_.endTime = 0;
	
	idle_.startTime = 0;
	idle_.endTime = 0;
	
	header_.startTime = 0;
	header_.endTime = 0;
	
	frame_.startTime = 0;
	frame_.endTime = 0;

	collisionOccurred_ = false;
	linkBusy_ = false;
	ackRecieved_ = false;
	ackSignal_ = msgId_ + RANDOM_ACK_OFFSET;
}

///////////////////////////////////////////////////////////////////////////////
// @brief Destructor
// @params void
// @return void
///////////////////////////////////////////////////////////////////////////////
DcfProtocol::~DcfProtocol(void)
{

}

///////////////////////////////////////////////////////////////////////////////
// @brief execute the protocol
// @params void
// @return void
///////////////////////////////////////////////////////////////////////////////
void DcfProtocol::execute(void)
{
	std::cout << "Executing DcfProtocol\n";
	printCurrState();
	switch (currState_)
	{
	case IDLE: 
		if(true)
		//if (pSimState_->getNextArrivalSlot())
		{
			difs_.startTime = currSlot_;
			difs_.endTime = difs_.startTime + SimParamsT::DIFSDuration;
			difs_.init = true;
			nextState_ = DIFS;
			if(pMessage_ != NULL)
			{
				delete pMessage_;
			}
			else
			{
				pMessage_ = new Message(msgId_);
			}
		}

	case DIFS: 
		if (difs_.init)
		{   
			linkBusy_ = false;
			difs_.startTime = currSlot_;
			difs_.endTime = difs_.startTime + SimParamsT::DIFSDuration;
			difs_.init = false;
		}

		if (currSlot_ < difs_.endTime)
		{
		    linkBusy_ = (pSimState_->getSignals() != 0); //if there is activity on the link wait 
		}
		else
		{
			if (linkBusy_)
			{
				nextState_ = DIFS;
				difs_.init = true;
			}
			else
			{
				nextState_ = BACKOFF;
				backoff_.init = true;
			}
		}
		break;
		case BACKOFF: 
			if(backoff_.init)
			{
				if (backoffInterrupted_ == true)
				{
					//do nothing
				}
				else
				{
				backoffTime_ = getNewBackoff();
				}
				backoff_.init = false;
			}
			else
			{
				//todo need to determine what will happen in the sifs state;
				if (pSimState_->getSignals() == 0)
				{
					backoffTime_--;
				}
				else
				{
					nextState_ = DIFS;
					backoffInterrupted_ = true;
				}
			}
			if (backoffTime_ == 0)
			{
				nextState_ = HDR;
				header_.init = true;
				backoffInterrupted_ = false;
			}
			break;
		case HDR: 
			if (header_.init)
			{
				header_.startTime = currSlot_;
				header_.endTime = currSlot_ + 1; //since the header size was not defined we will go ahead
				                                 //and assume it is only 1 slot
				header_.init = false;
				nextState_ = FRAME;
				frame_.init = true;

				//broadcast out header to receiever and any other stations listening.
			}
			break;
		case FRAME:
			if (frame_.init)
			{
				frame_.startTime = currSlot_;
				frame_.endTime = currSlot_ + SimParamsT::dataFrameSize;
				frame_.init = false;
			}
			else
			{
				if (frame_.endTime == currSlot_)
				{
					nextState_ = SIFS;
					sifs_.init = true;
				}
				else
				{
					//broadcast frame
				}
			}
			break;
		case SIFS: 
			if (sifs_.init)
			{
				sifs_.startTime = currSlot_;
				sifs_.endTime = currSlot_ + SimParamsT::SIFSDuration;
				sifs_.init = false;
			}
			else
			{
				if (sifs_.endTime == currSlot_)
				{
					nextState_ = ACK;
					ack_.init = true;
				}
				else
				{
					//do nothing, just listen
				}
			}
			break;
		case ACK: 
			if (ack_.init)
			{
				ack_.startTime = currSlot_;
				ack_.endTime = currSlot_ + SimParamsT::ACKDuration;
				ack_.init = false;
			}
			else
			{
				unsigned long ackSignal = pSimState_->getSignals();
				if (ackSignal == ackSignal_)
				{
					ackRecieved_ = true;
				}
			}
			if (ack_.endTime == currSlot_)
			{
				//check if we received the acknowledgment. if not our msg must have been corrupted.
				if (ackRecieved_)
				{
					nextState_ = DIFS;
					difs_.init = true;
				}
				else
				{
					collisionOccurred_ = true;
					nextState_ = DIFS;
					difs_.init = true;
				}
			}
			break;
	}
	currState_ = nextState_;
}

///////////////////////////////////////////////////////////////////////////////
// @brief get a new backoff random number from [0, CW0-1]
// @params void
// @return int return random number
///////////////////////////////////////////////////////////////////////////////
int DcfProtocol::getNewBackoff(void)
{
	return rand() % SimParamsT::CW0;
}

///////////////////////////////////////////////////////////////////////////////
// @brief print the current state
// @params void
// @return void
///////////////////////////////////////////////////////////////////////////////
void DcfProtocol::printCurrState(void) const
{
	std::cout << "CurrentState is: " << static_cast<int>(currState_) << std::endl;;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////