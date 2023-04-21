// Name: Vishwam Shailesh Kapadia
// Seneca Student ID: 154933212
// Seneca email: vkapadia3@myseneca.ca
// Date of completion: 19-11-2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>

namespace sdds {

    class Utilities {

        std::size_t m_widthField = 1;
        static char m_delimiter;

    public:
        void setFieldWidth(std::size_t newWidth);
        std::size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, std::size_t& next_pos, bool& more);
        static void setDelimiter(const char newDelimiter);
        static char getDelimiter();
    };
}
#endif 
