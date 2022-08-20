/*************************************************
    Name: Aayush Shrestha						 *
    ID: 011756637								 *
    CPTS 122									 *
    Programming Assignment: PA5					 *
                                                 *
    File: queue.h						         *
                                                 *
*///**********************************************

#pragma once

#include "queueNode.h"
#include "header.h"
#include "Data.h"


class Queue
{
public: // Member functions
    Queue();
    ~Queue();

    void printQueue(QueueNode*node);

    bool isEmpty();

    int enqueue(Data& newData);

    void dequeue();

    int calcTotalServiceTime(QueueNode*nextNode);

    QueueNode* getHead();

    QueueNode* getTail();


private:
    QueueNode* pHead;
    QueueNode* pTail;
};