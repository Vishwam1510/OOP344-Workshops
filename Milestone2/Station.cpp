// Name: Vishwam Shailesh Kapadia
// Seneca Student ID: 154933212
// Seneca email: vkapadia3@myseneca.ca
// Date of completion: 13-12-2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "Station.h"

using namespace std;

namespace sdds {

    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 1;

    Station::Station(string& record)
    {
        Utilities ut;
        size_t ps = 0;
        bool other;
        m_id = id_generator++;

        try {

            m_name = ut.extractToken(record, ps, other);
            m_nextSerialNum = stoi(ut.extractToken(record, ps, other));
            m_stockQty = stoi(ut.extractToken(record, ps, other));
            m_widthField = max(ut.getFieldWidth(), m_widthField);
            m_desc = ut.extractToken(record, ps, other);

        }
        catch (string& e) {
            cout << e;
        }
    }

    string& Station::getItemName()
    {
        return m_name;
    }


    size_t Station::getNextSerialNumber()
    {
        return m_nextSerialNum++;
    }

    size_t Station::getQuantity()
    {
        return m_stockQty;
    }

    void Station::updateQuantity()
    {
        m_stockQty--;
        if (0 > m_stockQty)
            m_stockQty = 0;
    }

    void Station::display(ostream& os, bool f)
    {
        os << setfill('0') << setw(3) << right << m_id;
        os << " | " << setw(m_widthField) << setfill(' ') << left << m_name;
        os << " | " << setfill('0') << setw(6) << right << m_nextSerialNum << " | ";

        if (f)
        {
            os << right << setw(4) << setfill(' ') << m_stockQty << " | ";

            os << left << m_desc << endl;
        }
        else os << endl;
    } 
}