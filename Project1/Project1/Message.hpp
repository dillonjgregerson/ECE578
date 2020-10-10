#pragma once
#include "SimParamsT.hpp"
#include <cstdlib>
class Message
{
	int msgId_;
	int header_; //contains the NAV
	const static int MSG_FRAME_LENGTH = 50; //we are taking the header to be part of the frame
	unsigned int frame_[MSG_FRAME_LENGTH];
public:
	explicit Message(int msgId):msgId_(msgId) 
	{
		header_ = SimParamsT::ACKDuration + SimParamsT::dataFrameSize + SimParamsT::SIFSDuration;
		populateMessage();
	}

	virtual ~Message(void) {}
	int getMsgId(void) { return msgId_; }
	bool operator ==(Message rhs)
	{
		return (msgId_ == rhs.getMsgId());
	}

	int operator +(Message rhs)
	{
		return (msgId_ + rhs.getMsgId());
	}

	bool operator !=(Message rhs)
	{
		return (msgId_ != rhs.getMsgId());
	}
	void populateMessage(void) 
	{
		unsigned int checksum = 0;
		checksum += msgId_;
		frame_[0] = header_;
		for (unsigned int i = 1; i < MSG_FRAME_LENGTH-1;i++)
		{
			frame_[i] = rand() % 20;
			checksum += frame_[i];
		}
		frame_[MSG_FRAME_LENGTH] = checksum;
	};
};