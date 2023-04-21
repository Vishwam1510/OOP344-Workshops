// Name: Vishwam Shailesh Kapadia
// Seneca Student ID: 154933212
// Seneca email: vkapadia3@myseneca.ca
// Date of completion: 19-11-2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iomanip>
#include <string>
#include "Station.h"

namespace sdds {

    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;

    Station::Station(const std::string& str) 
    {
        Utilities util;
        bool more;
        size_t next_pos = 0;
        this->m_id = ++id_generator;
        this->m_name = util.extractToken(str, next_pos, more);
        this->m_serialNumber = std::stoi(util.extractToken(str, next_pos, more));
        this->m_quantity = std::stoi(util.extractToken(str, next_pos, more));
        m_widthField = std::max(util.getFieldWidth(), m_widthField);
        this->m_desc = util.extractToken(str, next_pos, more);
    }

    const std::string& Station::getItemName() const 
    {
        return this->m_name;
    }

    unsigned int Station::getNextSerialNumber() 
    {
        return this->m_serialNumber++;
    }

    unsigned int Station::getQuantity() const 
    {
        return this->m_quantity;
    }

    void Station::updateQuantity() {
        if (m_quantity > 0) 
        {
            this->m_quantity--;
        }
    }

    void Station::display(std::ostream& os, bool full) const 
    {
        os << std::setw(3) << std::setfill('0') << this->m_id
            << " " << Utilities::getDelimiter() << " "
            << std::setw(m_widthField) << std::setfill(' ') << std::left << this->m_name
            << " " << Utilities::getDelimiter() << " "
            << std::setw(6) << std::right << std::setfill('0') << this->m_serialNumber
            << " " << Utilities::getDelimiter() << " ";
        if (full) {
            os << std::setw(4) << std::setfill(' ')
                << this->m_quantity << " " << Utilities::getDelimiter() << " "
                << this->m_desc;
        }
        os << std::endl;
    }
}
