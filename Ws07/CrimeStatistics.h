/*
*****************************************************************************
                          Workshop - #4
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

#ifndef CRIMESTATISTICS_H
#define CRIMESTATISTICS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include <numeric>
#include <iomanip>


namespace sdds {

    struct Crime {
        std::string province;  
        std::string district;  
        std::string crime;  
        unsigned int noCases;  
        unsigned int year;  
        unsigned int m_resolved;
    } ; 
    class CrimeStatistics {
            std::vector <Crime> crimeCollection ;
        public:
            CrimeStatistics(const char* fName) ; 
            void display(std::ostream& out) const ;
            void sort(std::string fieldName) ; 
            void cleanList() ; 
            bool inCollection(std::string crimeType) const ;
            std::list<Crime> getListForProvince(std::string provinceName) const; 
    };
    std::ostream& operator<<(std::ostream& out, const Crime& theCrime) ; 
}
#endif