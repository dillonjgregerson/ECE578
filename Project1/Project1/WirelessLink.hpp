///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
#pragma once

class WirelessLink
{
public:
	WirelessLink(void);
	~WirelessLink(void);
	int listen(void)const;
	void setSignal(int sigValue);
protected:
	int currSignal_;
	static WirelessLink  instance_;
	static WirelessLink* pInstance_;

};