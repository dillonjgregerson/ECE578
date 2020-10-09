
#include "WirelessLink.hpp"

WirelessLink::WirelessLink(void)
{
}

WirelessLink::~WirelessLink(void)
{
}

int WirelessLink::listen(void)const 
{
	return currSignal_;
}

void WirelessLink::setSignal(int signal)
{
	currSignal_ = signal;
}
