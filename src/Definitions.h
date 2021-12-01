#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#ifndef ITM_FILE_PATH
#error "ITEM DATA FILE MISSING! Make sure you run CMake properly"
#endif
#ifndef USR_FILE_PATH
#error "USR DATA FILE MISSING! Make sure you run CMake properly"
#endif

#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <fstream>


// #define NDEBUG // uncomment to disable assert()
#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))


#ifndef MAX_FEATURES
#define MAX_FEATURES 8
#endif

class Entry{
    std::string id;
    double features[MAX_FEATURES];
public:
    Entry()
    {
        for(int i = 0; i < MAX_FEATURES; i++){
            features[i] = -1;
        }
    }

    std::string getId() const
    {
        return id;
    }

    void setId(std::string newId)
    {
        id = newId;
    }

    void setFeatures(std::vector<double> vecIn)
    {
        assertm(vecIn.size() == MAX_FEATURES, "Entry::setFeatures - vector used is not complete");

        for(int i = 0; i < MAX_FEATURES; i++){
            features[i] = vecIn.at(i);
        }
    }
};

class UserEntry: public Entry{
    int budget;
public:
    UserEntry(){Entry();}
    UserEntry(int budg){this->budget = budg;}

    static UserEntry createMeFrom(std::string line);

    friend std::ostream& operator<<(std::ostream& os, const UserEntry& a){
        os << "UserEntry[" << a.getId() <<"] - budget " << a.budget;
        return os;
    }
};



class ItemEntry: public Entry{
    int price;
public:
    ItemEntry(){Entry();}
    ItemEntry(int prc){this->price = prc;}

    static ItemEntry createMeFrom(std::string line);

    friend std::ostream& operator<<(std::ostream& os, const ItemEntry& a){
        os << "ItemEntry[" << a.getId() <<"] - price " << a.price;
        return os;
    }
};







///////////////////////////////////////////// Parse Lines To Classes /////////////////////////////////////////////

///
/// \brief UserEntry::createMeFrom
///         used in utils::parseCSVtoUsers()
///
/// \param line from the csv input file
/// \return a new UserEntry object
///
inline UserEntry UserEntry::createMeFrom(std::string line)
{
    UserEntry retUsr;
    std::istringstream lineStrm(line.c_str());
    std::string s;
    std::vector<double> vec;
    int i = 0;
    while (getline(lineStrm, s, ',')) {
        if(i == 0){
            i++;
            continue; //first column is useless
        }
        else if(i == 1){
            retUsr.setId(s); //second column is str id
        }else{
            double v = ::atof(s.c_str());
            vec.push_back(v); //everything else to the vec
        }
        i++;
    }
    double budg = vec.back(); // last is budget
    retUsr.budget = budg;
    vec.pop_back();
    retUsr.setFeatures(vec); // set features after pop
    return retUsr;
}

///
/// \brief ItemEntry::createMeFrom
///         used in utils::parseCSVtoItems()
///
/// \param line from the csv input file
/// \return a new ItemEntry object
///
inline ItemEntry ItemEntry::createMeFrom(std::string line)
{
    ItemEntry retItm;
    std::istringstream lineStrm(line.c_str());
    std::string s;
    std::vector<double> vec;
    int i = 0;
    while (getline(lineStrm, s, ',')) {
        if(i == 0){
            i++;
            continue; //first column is useless
        }
        else if(i == 1){
            retItm.setId(s); //second column is str id
        }else{
            double v = ::atof(s.c_str());
            vec.push_back(v); //everything else to the vec
        }
        i++;
    }
    double pr = vec.back(); // last is price
    retItm.price = pr;
    vec.pop_back();
    retItm.setFeatures(vec); // set features after pop
    return retItm;
}

#endif // DEFINITIONS_H
