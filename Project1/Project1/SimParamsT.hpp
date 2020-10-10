///////////////////////////////////////////////////////////////////////////////
// Project: ECE 578 Project 1 The Distributed Coordination function (DCF) of 802.11
// Author: Dillon Gregerson
// Originated: 10/10/2020
///////////////////////////////////////////////////////////////////////////////
#pragma once
#ifndef SIM_PARAMS_T_HPP
#define SIM_PARAMS_T_HPP

namespace SimParamsT
{
	static int dataFrameSize = 5;         //units- slots
	static double slotDuration = 0.000015;  //units - seconds
	static int SIFSDuration = 1;           //units - slots
	static int CW0	         = 4;           //units - slots
	static int lambdaA[6] = { 200, 300, 500, 1000, 2000 }; //units -frames/sec
	static int ACKDuration = 2;  //units - slots
	static int DIFSDuration = 2; //units - slots
	static int CTSDuration = 2;  //units - slots
	static int RTSDuration  = 2;  //units - slots
	static int tranmsmissionRate =  24; //units - Mbits/sec
	static int CWMax = 1024; //units - slots
	static float simulationTime = 10; //units - seconds
}
#endif //SIM_PARAMS_T