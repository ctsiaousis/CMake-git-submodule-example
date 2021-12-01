#include "UserEntry.h"

UserEntry::UserEntry()
{
    Entry();
    for(int i = 0; i < MAX_FEATURES; i++) variance[i][i] = 2;
}

UserEntry UserEntry::createMeFrom(std::string line)
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
