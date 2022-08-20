#pragma once
#include "header.h"

class Data
{
public: // Member functions

    Data() : customerNumber(0), serviceTime(0), totalTime(0)
    {
    
    }

    Data(int customer_number, int total_time, int service_time) :
        customerNumber(customer_number), totalTime(total_time), 
        serviceTime(service_time) 
    {
    
    }

    ~Data() {}


   
    int getCustomerNumber()const { return customerNumber; }
    int getServiceTime()const { return serviceTime; }
    int getTotalTime()const { return totalTime; }

private:
    int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
    int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
    int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
}; // This memory needs to be allocated on the heap!