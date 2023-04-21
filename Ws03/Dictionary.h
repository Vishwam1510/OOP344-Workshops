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

#ifndef _SDDS_DICTIONARY_H
#define _SDDS_DICTIONARY_H

namespace sdds
{
    class Dictionary
    {
        std::string m_term{};
        std::string m_definition{};
    public:
        const std::string& getTerm() const;
        const std::string& getDefinition() const;
        Dictionary();                             
        Dictionary(const std::string& term, const std::string& definition); 
        Dictionary(const Dictionary& D);              
        Dictionary& operator=(const Dictionary& D); 
        bool operator == (const Dictionary& D) const; 
        void display(std::ostream& os) const;       
    };
    std::ostream& operator<< (std::ostream& os, const Dictionary& D);
}
#endif