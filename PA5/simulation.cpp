/*************************************************
	Name: Aayush Shrestha						 *
	ID: 011756637								 *
	CPTS 122									 *
	Programming Assignment: PA5					 *
												 *
	File: sumulation.cpp		 		         *
												 *
*///**********************************************

#include "simulation.h"
#include "queue.h"

using std::cout;
using std::endl;

/***************************************************************
* Function: runSimulation()									   *
* Date Created: 											   *
* Date Last Modified: 03/10 							       *
* Description:	runs the entire program. is called in test.cpp *
				by function "run24()						   *
* Returns:													   *
															   *
***************************************************************/
void runSimulation(int time) 
{
	Queue normalLane;
	Queue expressLane;
	int normalLaneArrival = rand() + 5 % 1; // generate random number 1 to 5 for normal lane
	int expressLaneArrival = rand() + 8 % 1;// genenrate random number 1 to 8 for express lane
	int numCustomers = 0;
	int ntime = 0, etime = 0;
	int totalTime = 0;
	int normalTime = 0, expressTime = 0;
	int timeUntilNextNormalLane = 0, timeUntilNextExpressLane = 0;
	int sumTimeNormal = 0, serviceTimeNormal = 0, totalTimeNormal = 0;
	int sumTimeExpress = 0, serviceTimeExpress = 0, totalTimeExpress = 0;
	
	// time is the passed in value 
	while (totalTime < time)
	{

		if (normalTime < 0 && normalLane.isEmpty() == 0)
		{
			normalTime = normalLane.getTail()->getData()->getServiceTime();
		}
		if (expressTime < 0 && expressLane.isEmpty() == 0)
		{
			expressTime = expressLane.getTail()->getData()->getServiceTime();
		}



		if (normalTime == 0 && normalLane.isEmpty() == 0)
		{
			cout << "\ndis guy has checked out of the normal lane " 
				<< normalLane.getHead()->getData()->getCustomerNumber() << endl;

			ntime = normalLane.getHead()->getData()->getTotalTime();

			cout << "\nIt took " << normalLane.getHead()->getData()->getCustomerNumber() 
				<< ntime << " minutes to check out and exited at" << totalTime << endl;

			normalLane.dequeue();
			//system("pause");
		}

		if (expressTime == 0 && expressLane.isEmpty() == 0)
		{
			cout << "This customer has checked out of the express lane "
				<< expressLane.getHead()->getData()->getCustomerNumber() << endl;

			etime = expressLane.getHead()->getData()->getTotalTime();

			cout << "It took " << expressLane.getHead()->getData()->getCustomerNumber()
				<< etime << " minutes to check out and exited at " << totalTime << endl;

			expressLane.dequeue();
			//system("pause");
		}


		if (totalTime % 10 == 0)
		{
			cout << totalTime << " has passed" << endl;
			cout << "*Printing Queue for Normal Lane*" << endl;
			normalLane.printQueue(normalLane.getHead());
			//system("pause");
		}


		
		if (timeUntilNextNormalLane == 0)
		{
			sumTimeNormal = normalLane.calcTotalServiceTime(normalLane.getHead());
			serviceTimeNormal = rand() % 5 + 1;
			totalTimeNormal = sumTimeNormal + serviceTimeNormal;
			Data* newCustomer = new Data(numCustomers++, sumTimeNormal, serviceTimeNormal);

			normalLane.enqueue(*newCustomer);
			timeUntilNextNormalLane = rand() % 5 + 1;

			cout << newCustomer->getCustomerNumber() << " has entered normal lane at time "
				<< totalTime << endl;
			//system("pause");
		}
		else
		{
			timeUntilNextNormalLane--;
		}



		if (timeUntilNextExpressLane == 0)
		{
			sumTimeExpress = expressLane.calcTotalServiceTime(expressLane.getHead());
			serviceTimeExpress = rand() % 5 + 1;
			totalTimeExpress = sumTimeExpress + serviceTimeExpress;
			Data* newCustomer = new Data(numCustomers++, sumTimeExpress, serviceTimeExpress);

			expressLane.enqueue(*newCustomer);
			timeUntilNextExpressLane = rand() % 5 + 1;

			cout << newCustomer->getCustomerNumber() << "has entered normal lane at time"
				<< totalTime << endl;
			//system("pause");
		}
		else
		{
			timeUntilNextExpressLane--;
		}
	}


	totalTime++;
	normalTime--;
	expressTime--;
}
