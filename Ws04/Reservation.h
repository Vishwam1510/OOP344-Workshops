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

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

constexpr int ID_SIZE{11}; 
                         

namespace sdds {

class Reservation
{
   char m_id[ID_SIZE];
   std::string m_name;
   std::string m_email;
   unsigned m_guestCount;
   unsigned char m_day;  
   unsigned char m_hour; 
 public:
   Reservation();
   Reservation(const std::string& res);
   void update(int day, int time);
   friend std::ostream& operator<<(std::ostream&, const Reservation&);
};

}

#endif //! SDDS_RESERVATION_H
