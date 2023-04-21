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

#include "Restaurant.h"

namespace sdds {

void Restaurant::deallocate() {
   for (size_t i = 0; i < m_count; i++) {
      delete m_reservations[i];
   }
   delete[] m_reservations;
}


Restaurant::~Restaurant() { deallocate(); }


Restaurant::Restaurant(const Reservation* reservations[], size_t count) {  
   m_reservations = new Reservation*[count];
   for (size_t i = 0; i < count; i++) {
      
      m_reservations[i]  = new Reservation;
      *m_reservations[i] = *reservations[i];
   }
   m_count = count;
}

Restaurant::Restaurant(const Restaurant& restaurant) { *this = restaurant; }


Restaurant::Restaurant(Restaurant&& restaurant) {
   *this = std::move(restaurant);
}


Restaurant& Restaurant::operator=(const Restaurant& restaurant) {
   if (this != &restaurant) {
      deallocate();
      m_reservations = new Reservation*[restaurant.m_count];
      for (size_t i = 0; i < restaurant.m_count; i++) {
         m_reservations[i]  = new Reservation;
         *m_reservations[i] = *restaurant.m_reservations[i];
      }
      m_count = restaurant.m_count;
   }
   return *this;
}

Restaurant& Restaurant::operator=(Restaurant&& restaurant) {
   if (this != &restaurant) {
      deallocate();
      m_count                   = restaurant.m_count;
      m_reservations            = restaurant.m_reservations;
      restaurant.m_reservations = nullptr;
      restaurant.m_count        = 0;
   }
   return *this;
}


size_t Restaurant::size() const { return m_count; }

std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant) {
   static unsigned called = 0;
   called++;
   os << "--------------------------\nFancy Restaurant (" << called
      << ")\n--------------------------\n";
   if (restaurant.m_count > 0) {
      for (size_t i = 0; i < restaurant.m_count; i++) {
         os << *restaurant.m_reservations[i];
      }
   }
   else {
      os << "This restaurant is empty!\n";
   }

   os << "--------------------------\n";

   return os;
}

} 
