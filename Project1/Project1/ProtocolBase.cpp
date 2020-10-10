///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
#include "ProtocolBase.hpp"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
// @brief Constructor
// @params void
// @return void
///////////////////////////////////////////////////////////////////////////////
ProtocolBase::ProtocolBase(void)
{

}

///////////////////////////////////////////////////////////////////////////////
// @brief Destructor
// @params void
// @return N/A
///////////////////////////////////////////////////////////////////////////////
ProtocolBase::~ProtocolBase(void)
{

}

///////////////////////////////////////////////////////////////////////////////
// @brief chose the next action based on the protocol
// @params void
// @return void
///////////////////////////////////////////////////////////////////////////////
void ProtocolBase::nextAction(void)
{

}
///////////////////////////////////////////////////////////////////////////////
// @brief execute the protocol's next action
// @params void
// @return void
///////////////////////////////////////////////////////////////////////////////
void ProtocolBase::execute(void)
{
	std::cout << "executing Protocol Base\n";
}

///////////////////////////////////////////////////////////////////////////////
// @brief update the protocol's state info
// @params unsigned long signal, unsigned long currSlot
// @return void
///////////////////////////////////////////////////////////////////////////////
void ProtocolBase::updateState(unsigned long signal, unsigned long currSlot)
{
	currSignal_ = signal;
	currSlot_ = currSlot;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////