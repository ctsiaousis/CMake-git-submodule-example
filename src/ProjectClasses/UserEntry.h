#ifndef USERENTRY_H
#define USERENTRY_H

#include "Entry.h"

class UserEntry: public Entry{
    int budget;
public:
    UserEntry();

    ///
    /// \brief UserEntry::createMeFrom
    ///         used in utils::parseCSVtoUsers()
    ///
    /// \param line from the csv input file
    /// \return a new UserEntry object
    ///
    static UserEntry createMeFrom(std::string line);

    friend std::ostream& operator<<(std::ostream& os, const UserEntry& a){
        os << "UserEntry[" << a.getId() <<"] - budget " << a.budget;
        return os;
    }
};


#endif //USERENTRY_H
