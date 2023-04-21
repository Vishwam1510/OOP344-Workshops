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

#ifndef _SDDS_QUEUE_H
#define _SDDS_QUEUE_H
#include "Dictionary.h"

namespace sdds
{
   template <class T, unsigned CAPACITY>
   class Queue
   {
      T arr[CAPACITY]{};
      unsigned cnt{};
      static T dummy;

   public:
      Queue() {}
      virtual ~Queue() {} 
      virtual bool push(const T& item) 
      {
         bool check = true;
         if (cnt < CAPACITY)
         {
            arr[cnt] = item;
            ++cnt;
         }
         else
         {
            check = false;
         }
         return check;
      }
      T pop()
      {       
         T temp{}; 
         temp = arr[0];         
         for (auto i = 0u; i < cnt; i++)
         {            
            arr[i] = arr[i + 1];
         }
         --cnt;
         return temp;
      }
      unsigned size() const
      {
         return cnt;
      }
      std::ostream& display(std::ostream& os = std::cout) const
      {
         std::cout << "----------------------" << std::endl;
         std::cout << "| Dictionary Content |" << std::endl;
         std::cout << "----------------------" << std::endl;

         for (unsigned i = 0; i < cnt; i++)
         {
            os << arr[i] << std::endl;
         }

         std::cout << "----------------------" << std::endl;
         return os;
      }

      T operator [] (unsigned idx) const
      {
         return idx < cnt ? arr[idx] : dummy;
      }

   };

   template<typename T, unsigned CAPACITY>
   T Queue<T, CAPACITY>::dummy{};
   template<>
   Dictionary Queue<Dictionary, 100u>::dummy = Dictionary("Empty Term", "Empty Substitute");
}

#endif