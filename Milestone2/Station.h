// Name: Vishwam Shailesh Kapadia
// Seneca Student ID: 154933212
// Seneca email: vkapadia3@myseneca.ca
// Date of completion: 13-12-2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>
#include "Utilities.h"

using namespace std;
namespace sdds {

    class Station {
        int m_id;
        string m_name;
        string m_desc;
        unsigned m_nextSerialNum;
        unsigned m_stockQty;
        static size_t m_widthField;
        static size_t id_generator;
    public:
        Station(string& record);
        string& getItemName();
        size_t getNextSerialNumber();
        size_t getQuantity();
        void updateQuantity();
        void display(ostream& os, bool full);
    };
}
#endif 