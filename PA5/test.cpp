/*************************************************
	Name: Aayush Shrestha						 *
	ID: 011756637								 *
	CPTS 122									 *
	Programming Assignment: PA5					 *
												 *
	File: 	test.cpp				 	         *
												 *
*///**********************************************

#include "simulation.h"
#include "test.h"


using std::cout;
using std::endl;



/***************************************************************
* Function:	testEmptyEnqueue								   *
* Date Created: 											   *
* Date Last Modified: 03/11								       *
* Description:	tests if enqueue() is working properly		   *
* Returns:													   *
															   *
***************************************************************/
void Test::testEmptyEnqueue()
{
	Data* nData = new Data(5, 6, 7);
	Queue* temp = nullptr;
	temp->enqueue(*nData);

	if (nData->getCustomerNumber() == temp->getHead()->getData()->getCustomerNumber())
	{
		cout << "enqueue works for empty" << endl;
	}
	else
	{
		cout << "enqueue did not work for empty" << endl;
	}

}



/***************************************************************
* Function:	testOneEnqueue									   *
* Date Created: 											   *
* Date Last Modified: 03/11								       *
* Description:	tests if enqueue() is working properly		   *
* Returns:													   *
															   *
***************************************************************/
void Test::testOneEnqueue()
{
	Queue* one = nullptr;
	Data* front = new Data(8, 9, 10);
	Data* rear = new Data(11, 12, 13);
	
	one->enqueue(*front);
	one->enqueue(*rear);

	if (front->getCustomerNumber() == one->getHead()->getData()->getCustomerNumber()
		&& rear->getCustomerNumber() == one->getTail()->getData()->getCustomerNumber())
	{
		cout << "enqueue one node is working" << endl;
	}
	else
	{
		cout << "enqueue one node is not working" << endl;
	}
}


/***************************************************************
* Function:	testOneEnqueue									   *
* Date Created: 											   *
* Date Last Modified: 03/11								       *
* Description:	tests if dequeue() is working properly		   *
* Returns:													   *
															   *
***************************************************************/
void Test::testOneDequeue()
{
	Queue* oneD = nullptr;
	Data* uno = new Data(5, 6, 7);

	oneD->enqueue(*uno);
	testEmptyEnqueue(); // check if enqueue is working
	
	oneD->dequeue();

	if (oneD->getHead() == nullptr && oneD->getTail() == nullptr)
	{
		cout << "one dequeue is working" << endl;
	}
	else
	{
		cout << "one dequeue is not working" << endl;
	}
}


/***************************************************************
* Function:	testTwoEnqueue									   *
* Date Created: 											   *
* Date Last Modified: 03/11								       *
* Description:	tests if dequeue() is working properly		   *
* Returns:													   *
															   *
***************************************************************/
void Test::testTwoDequeue()
{
	Data* uno = new Data(5, 6, 7);
	Data* dos = new Data(8, 9, 10);

	Queue* twoD = nullptr;
	twoD->enqueue(*uno);
	twoD->enqueue(*dos);

	twoD->dequeue(); 

	// since uno was inserted first. head ptr now must be poiting to dos
	if (twoD->getHead()->getData()->getTotalTime() == dos->getTotalTime())
	{
		cout << "dequeue is working for two nodes" << endl;
	}
	else
	{
		cout << "dequeue is not working for two nodes" << endl;
	}

}

/***************************************************************
* Function:	runTest()										   *
* Date Created: 											   *
* Date Last Modified: 03/11								       *
* Description: runs all of the tests						   *
* Returns:													   *
															   *
***************************************************************/
void Test::runTest()
{
	void testEmptyEnqueue();
	void testOneEnqueue();
	void testOneDequeue();
	void testTwoDequeue();
}

/***************************************************************
* Function:	run24()											   *
* Date Created: 											   *
* Date Last Modified: 03/11								       *
* Description:	runs runsimulation() for 24 hour			   *
* Returns:													   *
															   *
***************************************************************/
void Test::run24()
{
	cout << "running a 24 hour simulation!" << endl;

	runSimulation(1440); // 1440 minutes in a day;
}
