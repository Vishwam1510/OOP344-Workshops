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

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds {
class ConfirmationSender
{
   const Reservation** m_reservations{};
   size_t m_count{};

 public:
   ~ConfirmationSender();
   ConfirmationSender();
   ConfirmationSender(const ConfirmationSender& cs);
   ConfirmationSender(ConfirmationSender&& cs);
   ConfirmationSender& operator=(const ConfirmationSender& cs);
   ConfirmationSender& operator=(ConfirmationSender&& cs);
   ConfirmationSender& operator+=(const Reservation& res);
   ConfirmationSender& operator-=(const Reservation& res);
   friend std::ostream& operator<<(std::ostream& os,
                                   const ConfirmationSender& cs);
};
} 

#endif //! SDDS_CONFIRMATIONSENDER_H
