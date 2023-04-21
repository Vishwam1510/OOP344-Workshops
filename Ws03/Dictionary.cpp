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

#include <iostream>
#include <string>
#include <iomanip>

#include "Dictionary.h"


namespace sdds
{
    const std::string& sdds::Dictionary::getTerm() const { return m_term; }

    const std::string& sdds::Dictionary::getDefinition() const { return m_definition; }

    Dictionary::Dictionary()
    {
    }

    sdds::Dictionary::Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition } {}

    Dictionary::Dictionary(const Dictionary& D)
    {
        *this = D;
    }

    Dictionary& Dictionary::operator=(const Dictionary& D)
    {
        if (this != &D)
        {
            if (D.getTerm().c_str() && D.getDefinition().c_str())
            {
                m_term = D.getTerm();
                m_definition = D.getDefinition();
            }
            else
            {
                m_term = nullptr;
                m_definition = nullptr;
            }
        }
        return *this;
    }

    bool Dictionary::operator==(const Dictionary& D) const
    {
        return m_term == D.m_term && m_definition == D.m_definition ? true : false;
    }

    void Dictionary::display(std::ostream& os) const
    {
        os << std::setw(20) << std::right << getTerm() << ": " << getDefinition();
    }

    std::ostream& operator<<(std::ostream& os, const Dictionary& D)
    {
        D.display(os);
        return os;
    }

}