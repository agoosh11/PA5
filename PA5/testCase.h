#pragma once
#include "Data.h"
#include "Queue.h"
#include "QueueNode.h"
#include "runApp.h"

class testCase
{
	testCase();
	~testCase();
	void test();
	void tcEmptyEnqueue();
	void tcOneNodeEnqueue();
	void tcOneNodeDequeue();
	void tcTwoNodeDequeue();
	void runSim();
	void runSim24(int time);
	
};