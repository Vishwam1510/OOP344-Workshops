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


#include "Luxuryvan.h"

namespace sdds {
	Luxuryvan::Luxuryvan(std::istream& in) :Van(in) {
		char val = '\0';
		in >> val;
		if (val == 'e') {

			m_consumption = "electric van ";
		}
		else {
			throw std::string("Invalid record!");
		}
		in.ignore(1000, '\n');
	}
	void Luxuryvan::display(std::ostream& out) const {
		Van::display(out);
		out << " " << m_consumption << " *";
	}
	std::string Luxuryvan::consumption() const {
		return m_consumption;
	}
}