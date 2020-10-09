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