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

#ifndef SDDS_VAN_H
#define SDDS_VAN_H

#include <iostream>
#include "Vehicle.h"

namespace sdds {
	class Van : public Vehicle {
		std::string m_maker{};
		std::string m_type;
		std::string m_condition;
		std::string m_purpose;
		double m_topSpeed;
	public:
		Van(std::istream& in);
		std::string condition()const;
		std::string type() const;
		std::string usage() const;
		double topSpeed()const;
		void display(std::ostream& out) const;
	};
}
#endif // !VAN_H

