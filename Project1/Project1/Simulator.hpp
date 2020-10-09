#include <list>
#include "Station.hpp"
#include "SimState.hpp"

class Simulator
{
public:
    Simulator(void);
    ~Simulator(void);
	void update(void);
	bool addStation(Station* station);
protected:
	std::list<Station*> stations_;
	SimState* simState_;
};