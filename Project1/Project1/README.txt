The simulation code works as follows:

The Simulator is the overarching object that is responsible for running the simulation.

It has the basic functions of:
initialize
update

Objects:
1. Simulator:
	1.1 instatiates all the objects. For the simplest example this will include:
		a. A station and its corresponding protocol
		b. A receiver which will receive and respond to the signals 
		c. A singleton instance of the simulation state. This SimState object contains a WirelessLink
		   and a SlotTicker which keeps track of the global time (in slots).

    1.2 The update function loops through the update functions for each of the stations

2. Station
    2.1 The station object has two main functions, broadcast, listen, and ask its protocol object what to do next

3. Protocol:
    3.1 To enable a polymorphic approach, each protocol is derived from a "ProtocolBase" class.
    3.2 Each protocol's main function is to receive input from it's Station, and tell the station
	    what to do next.



