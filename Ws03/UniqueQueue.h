/*
*****************************************************************************
                          Workshop - #3 
Full Name  : Vishwam Shailesh Kapadia
Student ID#: 154933212
Email      : vkapadia3@myseneca.ca
Section    : NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


#ifndef _SDDS_UNIQUE_QUEUE_H
#define _SDDS_UNIQUE_QUEUE_H

#include <cmath>
#include "Queue.h"

namespace sdds
{
    template <typename T>
    class UniqueQueue : public Queue<T, 100>
    {
    public:
        bool push(const T& item)
        {
            bool check = true;
            for (auto i = 0u; i < this->size() && check; i++)
            {
                if (this->operator[](i) == item) check = false;
            }
            if (check)
            {
                check = Queue<T, 100>::push(item);
            }
            return check;
        }
    };
    template<>
    bool UniqueQueue<double>::push(const double& item)
    {
        bool check = true;
        for (auto i = 0u; i < this->size() && check; i++)
        {  
            if (std::fabs(this->operator[](i) - item) <= 0.005) check = false;
        }
        if (check) 
        {
            check = Queue<double, 100>::push(item);
        }

        return check;
    }
}
#endif