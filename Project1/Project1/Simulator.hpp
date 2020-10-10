#include <list>
#include "Station.hpp"
#include "SimState.hpp"

class Simulator
{
public:
	Simulator(void);
    ~Simulator(void);
	void update(void);
	bool addStation(StationBase* station);
	unsigned long getUniqueMsgId(void) const;

protected:
	std::list<StationBase*> stations_;
	SimState* simState_;
	unsigned int getNextArrivalSlot(void)
	{

	}
};