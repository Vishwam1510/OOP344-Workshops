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
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_

#include <string>
#include "Vehicle.h"

namespace sdds {
	class Car :public Vehicle
	{
		std::string m_maker = "";
		std::string m_condition = "";
		double m_topSpeed = 0;
	public:
		Car();
		Car(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}
#endif // !SDDS_CAR_H_
