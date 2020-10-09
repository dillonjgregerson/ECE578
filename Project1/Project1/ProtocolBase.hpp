#pragma once


class ProtocolBase
{
public:
	ProtocolBase();
	virtual ~ProtocolBase();
	virtual void nextAction(void);
	virtual void execute(void);
};