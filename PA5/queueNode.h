/*************************************************
	Name: Aayush Shrestha						 *
	ID: 011756637								 *
	CPTS 122									 *
	Programming Assignment: PA5					 *
												 *
	File: queueNode.h			  		         *
												 *
*///**********************************************

#pragma once

#include "data.h"
#include "header.h"


class QueueNode
{
public:
	QueueNode(Data*m_data);

	QueueNode*get_pNext();
	Data* getData();
	void setNext(QueueNode* p_Next);


	~QueueNode();

private:
	Data* mdata;
	QueueNode* pNext;
};
