#include "runApp.h"

void runApp()
{
	int runTime = 0, timer = 0;
	int expressArrivalTime = ((rand() % 5) + 1), normalArrivalTime = ((rand() % 5) + 4);
	Queue expressLane, normalLane;
	Data* express = new Data(1, (rand() % 5) + 1, 0); 
	Data* normal = new Data(1, (rand() % 5) + 4, 0);

	srand(time(NULL));

	cout << "Enter the simulation run time. " << endl;
	cin >> runTime;
	

	if (runTime != 0)
	{
		while(runTime>timer)
		{
			timer++;
			if ((timer == express->getTotalTime() && timer != 0) || (timer == expressArrivalTime))
			{
				expressLane.enqueue(*express);
				cout << "Customer " << express->getCustomerNumber() << "in Express Lane: " << "Service Time: " << timer << endl;
			}

			if ((timer == normal->getTotalTime() && timer != 0) || (timer == normalArrivalTime))
			{
				normalLane.enqueue(*normal);
				cout << "Customer " << normal->getCustomerNumber() << "in Normal Lane: " << "Service Time: " << timer << endl;
			}

			if (timer == express->getTotalTime())
			{
				Data dequeue = expressLane.dequeue();
				Data* temp;
				cout << "Customer " << dequeue.getCustomerNumber() << "in Express Lane is in queue." << "Service Time: " << timer << endl;
				temp = new Data(express->getCustomerNumber() + 1, (rand() % 5) + 1, timer);
				express = temp; 
			}

			if (timer == normal->getTotalTime())
			{
				Data dequeue = normalLane.dequeue();
				Data* temp;
				cout << "Customer " << dequeue.getCustomerNumber() << "in Normal Lane is in queue." << "Service Time: " << timer << endl;
				temp = new Data(normal->getCustomerNumber() + 1, (rand() % 5) + 4, timer);
				normal = temp;
			}

			if (timer % 10 == 0)
			{
				cout << "Time totaled: " << timer << endl;
				cout << "In Express Lane:" << endl;
				expressLane.printQueue();
				cout << "In Normal Lane" << endl;
				normalLane.printQueue();
			}

		}
		expressLane.~Queue();
	}
	else
	{
		cout << "Enter a valid time for the simulation." << endl;
	}
}