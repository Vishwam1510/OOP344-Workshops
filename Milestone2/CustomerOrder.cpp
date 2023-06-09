// Name: Vishwam Shailesh Kapadia
// Seneca Student ID: 154933212
// Seneca email: vkapadia3@myseneca.ca
// Date of completion: 13-12-2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <algorithm>
#include <vector>
#include <iomanip>
#include <iostream>
#include "CustomerOrder.h"
#include "Utilities.h"

namespace sdds {

    size_t CustomerOrder::m_widthField = 0;

    CustomerOrder::CustomerOrder()
    {

        m_cntItem = {};
        m_lstItem = {};
        m_name = {};
        m_product = {};

    }

    CustomerOrder::CustomerOrder(const std::string& str) : CustomerOrder()
    {
        Utilities utility;
        size_t npos{};
        bool more{ true };

        m_name = utility.extractToken(str, npos, more);
        m_product = utility.extractToken(str, npos, more);
        m_cntItem = count(str.begin(), str.end(), Utilities::getDelimiter()) - 1;

        std::vector<Item*> itemsList;
        do {
            itemsList.push_back(new Item(utility.extractToken(str, npos, more)));
        } while (more);

        m_lstItem = new Item * [m_cntItem];

        size_t i{}; //Index for the loop;
        std::for_each(itemsList.begin(), itemsList.end(), [&](Item* item) {
            m_lstItem[i] = item;
            i++;
            });

        m_widthField = std::max(utility.getFieldWidth(), m_widthField);
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept : CustomerOrder()
    {
        *this = std::move(src);
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
    {
        if (this != &src) {
            for (size_t i = 0; i < m_cntItem; i++) delete m_lstItem[i];
            delete[] m_lstItem;

            m_lstItem = src.m_lstItem;
            m_name = src.m_name;
            m_product = src.m_product;
            m_cntItem = src.m_cntItem;
            src.m_lstItem = nullptr;
            src.m_name = "";
            src.m_product = "";
            src.m_cntItem = 0;
        }
        return *this;
    }

    CustomerOrder::~CustomerOrder()
    {
        for (unsigned i = 0; i < m_cntItem; i++) {
            delete m_lstItem[i];
            m_lstItem[i] = nullptr;
        }

        delete[] m_lstItem;
    }

    bool CustomerOrder::isOrderFilled() const
    {
        //        bool isFilled = true;
        //        for (size_t i = 0; i < m_cntItem && isFilled; i++ )
        //            isFilled = m_lstItem[i]->m_isFilled;
        //
        //        return isFilled;

                /** Doesn't give proper output for some reason even though, logically, it is the same as the manual loop above. */
        return std::all_of(m_lstItem, (m_lstItem + m_cntItem), [](const Item* item) {
            return item->m_isFilled;
            });
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const
    {
        //        bool isItemFilled = true;
        //        for (size_t i = 0; i < m_cntItem && isItemFilled; i++)
        //            if (m_lstItem[i]->m_itemName == itemName) isItemFilled = m_lstItem[i]->m_isFilled;
        //
        //        return isItemFilled;

        /** Doesn't give proper output for some reason even though, logically, it is the same as the manual loop above. */
        return std::all_of(m_lstItem, m_lstItem + m_cntItem, [&itemName](Item* it) {
            if (it->m_itemName == itemName) return (it->m_isFilled);

            return true;
            });
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os)
    {
        bool flag = true;
        std::for_each(m_lstItem, m_lstItem + m_cntItem, [&](Item* item) {
            //std::cout<<station.getItemName() <<"-" << item->m_itemName <<"-\n";
            if (station.getItemName() == item->m_itemName && flag) {

                if (station.getQuantity() > 0) {

                    station.updateQuantity();

                    item->m_serialNumber = station.getNextSerialNumber();

                    item->m_isFilled = true;

                    os << "    Filled " << m_name << ", " << m_product << " [" << item->m_itemName << "]" << std::endl;

                    flag = false;

                }
                else os << "    Unable to fill " << m_name << ", " << m_product << " [" << item->m_itemName << "]" << std::endl;
            }


            });
    }

    std::string rtrim(const std::string s)
    {
        size_t end = s.find_last_not_of(' ');
        return (end == std::string::npos) ? "" : s.substr(0, end + 1);
    }

    void CustomerOrder::display(std::ostream& os) const
    {
        os << rtrim(m_name) << " - " << rtrim(m_product) << '\n';
        std::for_each(m_lstItem, m_lstItem + m_cntItem, [&](Item* item) {
            os << "[" << std::setw(6) << std::setfill('0') << item->m_serialNumber << "] " << std::setfill(' ') << std::setw(CustomerOrder::m_widthField) << setiosflags(std::ios::left) << item->m_itemName << resetiosflags(std::ios::left) << "  - ";
            if (item->m_isFilled)
                os << "FILLED";
            else
                os << "TO BE FILLED";
            os << std::endl;
            });
    }
}
