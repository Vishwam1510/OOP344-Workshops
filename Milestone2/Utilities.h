// Name: Vishwam Shailesh Kapadia
// Seneca Student ID: 154933212
// Seneca email: vkapadia3@myseneca.ca
// Date of completion: 13-12-2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>
#include <iostream>

using namespace std;

namespace sdds {

    class Utilities {

        std::size_t m_widthField = 1;
        static char m_delimiter;

    public:

        void setFieldWidth(size_t newWidth);        
        size_t getFieldWidth();
        string extractToken(const string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();

    };
}
#endif
