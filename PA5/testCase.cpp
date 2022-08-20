#include "testCase.h"

void testCase::test()
{
	tcEmptyEnqueue();
	tcOneNodeDequeue();
	tcOneNodeDequeue();
	tcTwoNodeDequeue();
	runSim();

}

testCase::~testCase() {}

void testCase::runSim(void) 
{
	cout << "running a 24 hours simulation" << endl;
	system("pause");
	runSim24(1440);
}

void testCase::tcEmptyEnqueue()
{
	Queue testEmpty;
	Data* testData = new Data(7, 9, 12);
	testEmpty.enqueue(*testData);
	if (testData->getCustomerNumber() == testEmpty.
}

void testCase::tcOneNodeDequeue()
{

}

void testCase::tcTwoNodeDequeue()
{

}

void testCase::tcOneNodeEnqueue()
{

}

