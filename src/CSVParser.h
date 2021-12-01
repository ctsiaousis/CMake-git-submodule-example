#ifndef CSVPARSER_H
#define CSVPARSER_H

#include "Definitions.h"

namespace utils {

static std::vector<UserEntry> parseCSVtoUsers(){
    std::string line;
    std::ifstream myfile((USR_FILE_PATH));
    assertm (myfile.is_open(), "Could not open user file");

    std::vector<UserEntry> retUsers;

    int valid = 0;
    while ( getline (myfile,line) ){
        if(valid)
            retUsers.push_back( UserEntry::createMeFrom(line) );
        valid++;
    }
    myfile.close();

    return retUsers;
}

static std::vector<ItemEntry> parseCSVtoItems(){
    std::string line;
    std::ifstream myfile((ITM_FILE_PATH));
    assertm (myfile.is_open(), "Could not open user file");

    std::vector<ItemEntry> retItems;

    int valid = 0;
    while ( getline (myfile,line) ){
        if(valid)
            retItems.push_back( ItemEntry::createMeFrom(line) );
        valid++;
    }
    myfile.close();

    return retItems;
}

}

#endif // CSVPARSER_H
