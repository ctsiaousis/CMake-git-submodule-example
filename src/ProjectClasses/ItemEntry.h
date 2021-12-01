#ifndef ITEMENTRY_H
#define ITEMENTRY_H

#include "Entry.h"


class ItemEntry: public Entry{
    int price;
public:
    ItemEntry();

    ///
    /// \brief ItemEntry::createMeFrom
    ///         used in utils::parseCSVtoItems()
    ///
    /// \param line from the csv input file
    /// \return a new ItemEntry object
    ///
    static ItemEntry createMeFrom(std::string line);

    friend std::ostream& operator<<(std::ostream& os, const ItemEntry& a){
        os << "ItemEntry[" << a.getId() <<"] - price " << a.price;
        return os;
    }
};


#endif //ITEMENTRY_H
