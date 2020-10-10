#include "ProtocolBase.hpp"
#include <iostream>
ProtocolBase::ProtocolBase(void)
{

}

ProtocolBase::~ProtocolBase(void)
{

}

void ProtocolBase::nextAction(void)
{

}

void ProtocolBase::execute(void)
{
	std::cout << "executing Protocol Base\n";
}

void ProtocolBase::updateState(unsigned long signal, unsigned long currSlot)
{
	currSignal_ = signal;
	currSlot_ = currSlot;
}