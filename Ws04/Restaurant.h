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

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"
namespace sdds {
class Restaurant
{
   size_t m_count{};
   Reservation** m_reservations{};
   void deallocate();

 public:
   ~Restaurant();
   Restaurant(const Reservation* reservations[], size_t count);
   Restaurant(const Restaurant& restaurant);
   Restaurant(Restaurant&& restaurant);
   Restaurant& operator=(const Restaurant& restaurant);
   Restaurant& operator=(Restaurant&& restaurant);
   size_t size() const;
   friend std::ostream& operator<<(std::ostream&, const Restaurant& restaurant);
};

} 

#endif // !SDDS_RESTAURANT_H
