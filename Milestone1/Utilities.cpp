// Name: Vishwam Shailesh Kapadia
// Seneca Student ID: 154933212
// Seneca email: vkapadia3@myseneca.ca
// Date of completion: 19-11-2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

namespace sdds {

    char Utilities::m_delimiter{};

    void Utilities::setFieldWidth(std::size_t newWidth) 
    {
        this->m_widthField = newWidth;
    }

    std::size_t Utilities::getFieldWidth() const 
    {
        return this->m_widthField;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        std::string token;
        size_t pos = str.find(m_delimiter, next_pos);
        if (pos != std::string::npos) 
        {
            token = str.substr(next_pos, pos - next_pos);
            next_pos = pos + 1;
            more = true;
        }
        else 
        {
            token = str.substr(next_pos);
            more = false;
        }
        if (token.empty()) 
        {
            more = false;
            throw "ERROR: No token found before the delimiter";
        }
        setFieldWidth(std::max(this->m_widthField, token.length()));
        token.erase(0, token.find_first_not_of(' '));
        token.erase(token.find_last_not_of(' ') + 1);
        return token;
    }

    void Utilities::setDelimiter(const char newDelimiter) 
    {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter() 
    {
        return m_delimiter;
    }
}
