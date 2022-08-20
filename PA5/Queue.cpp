/*************************************************
	Name: Aayush Shrestha						 *
	ID: 011756637								 *
	CPTS 122									 *
	Programming Assignment: PA5					 *
												 *
	File: Queue.cpp								 *
												 *
*///**********************************************

#include "queue.h"
#include "header.h"

using std::cout;
using std::endl;

Queue::Queue() // default constructor
{
	pHead = nullptr;
	pTail = nullptr;
}

Queue::~Queue()
{

}

/***************************************************************
* Function:	isEmpty()										   *
* Date Created: 											   *
* Date Last Modified: 03/08								       *
* Description:	checks if Queue is empty					   *
* Returns:													   *
															   *
***************************************************************/
bool Queue::isEmpty()
{
	if (pHead == nullptr && pTail == nullptr)
	{
		return 1;
	}
	else return 0;
}

/***************************************************************
* Function:	enqueue()										   *
* Date Created: 											   *
* Date Last Modified: 03/08								       *
* Description:	inserts data at the Tail of the queue		   *
* Returns:													   *
															   *
***************************************************************/
int Queue::enqueue(Data&nData)
{

	Data* temp = new Data(nData);
	QueueNode* node = new QueueNode(temp);

	if (temp == nullptr)
	{
		return 0;
	}
	else if (temp != nullptr)
	{
		if (pHead == nullptr)
		{
			pHead = node;
			pTail = node;
		}
		else
		{
			pTail->setNext(node);
			pTail = node;

			return 1;
		}
	}
}

/***************************************************************
* Function:	dequeue()										   *
* Date Created: 											   *
* Date Last Modified: 03/08								       *
* Description:	removes data from the Head of a queue		   *
* Returns:													   *
															   *
***************************************************************/
void Queue::dequeue()
{
	QueueNode* temp = nullptr;
	if (pHead == pTail) 
	{
		// only one data
		temp = pHead;
		pHead = nullptr;
		pTail = nullptr;

		delete temp;
	}
	else
	{
		// more than one data
		temp = pHead;
		pHead = pHead->get_pNext();
		// get_pNext is in "queueNode.cpp" line 4

		delete temp;
	}
}

QueueNode* Queue::getHead()
{
	return pHead;
}

QueueNode* Queue::getTail()
{
	return pTail;
}

/***************************************************************
* Function:	calcTotalServiceTime()							   *
* Date Created: 											   *
* Date Last Modified: 03/10								       *
* Description:	calculates the total service time			   *
* Returns:													   *
															   *
***************************************************************/
int Queue::calcTotalServiceTime(QueueNode* nextNode)
{
	int time = 0;

	if (nextNode != nullptr)
	{
		time = nextNode->getData()->getServiceTime();
		
		return calcTotalServiceTime(nextNode->get_pNext()) + time;
	}

	return time;
}


/***************************************************************
* Function:	printQueue()									   *
* Date Created: 											   *
* Date Last Modified: 03/09								       *
* Description:	prints the entire Queue						   *
* Returns:													   *
															   *
***************************************************************/

void Queue::printQueue(QueueNode* node)
{
	if (node != nullptr)
	{
		cout << node->getData()->getCustomerNumber() << endl;
		printQueue(node->get_pNext());
	}
	else
	{
		cout << endl;
	}
}

