/*
*****************************************************************************
						  Workshop - #6
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


#pragma once
#ifndef SDDS_UTILITIES_H_
#define SDDS_UTILITIES_H_

#include "Car.h"
#include "Van.h"
#include "Racecar.h"
#include "Luxuryvan.h"

namespace sdds 
{
	Vehicle* createInstance(std::istream& in);
}

#endif // !SDDS_UTILITIES_H_