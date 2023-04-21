// Name: Vishwam Shailesh Kapadia
// Seneca Student ID: 154933212
// Seneca email: vkapadia3@myseneca.ca
// Date of completion: 13-12-2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
#include <iostream>

using namespace std;

namespace sdds
{
    string WHITESPACE = " \n\r\t\f\v";

    string ltrim(string& str)
    {
        size_t fist = str.find_first_not_of(WHITESPACE);
        return (fist == string::npos) ? "" : str.substr(fist);
    }

    char Utilities::m_delimiter{};

    void Utilities::setFieldWidth(size_t width_newly)
    {
        m_widthField = width_newly;
    }

    size_t Utilities::getFieldWidth()
    {
        return m_widthField;
    }

    string Utilities::extractToken(const string& my_str, size_t& next_pos, bool& more)
    {
        size_t pos = (my_str.find(getDelimiter(), next_pos));
        string token = my_str.substr(next_pos, pos - next_pos);
        token = ltrim(token);
        if (pos == next_pos)
        {
            more = false;
            throw string("Failed to find the delimiter");
        }
        next_pos = pos + 1;
        setFieldWidth(max(m_widthField, token.size()));
        more = pos != string::npos;
        return token;
    }    

    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }
}
