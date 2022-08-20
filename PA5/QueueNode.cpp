/*************************************************
    Name: Aayush Shrestha						 *
    ID: 011756637								 *
    CPTS 122									 *
    Programming Assignment: PA5					 *
                                                 *
    File: QueueNode.cpp		  	                 *
                                                 *
*///**********************************************


#include "header.h"
#include "queueNode.h"


QueueNode* QueueNode::get_pNext()
{
	// allows access to pNext for enqueue and dequeue.
	return pNext;
}

Data* QueueNode::getData()
{
	return mdata;
}

QueueNode::QueueNode(Data*m_data)
{
	mdata = m_data;
}
void QueueNode::setNext(QueueNode*p_Next)
{
    pNext = p_Next;
}

QueueNode::~QueueNode()
{

}