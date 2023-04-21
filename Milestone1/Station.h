// Name: Vishwam Shailesh Kapadia
// Seneca Student ID: 154933212
// Seneca email: vkapadia3@myseneca.ca
// Date of completion: 19-11-2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include "Utilities.h"

namespace sdds {

    class Station {
        int m_id;
        std::string m_name;
        unsigned int m_serialNumber;
        unsigned int m_quantity;
        std::string m_desc;
        static size_t m_widthField;
        static size_t id_generator;

    public:
        Station(const std::string& str);
        const std::string& getItemName() const;
        unsigned int getNextSerialNumber();
        unsigned int getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}
#endif 
