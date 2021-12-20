#include "ItemEntry.h"


ItemEntry::ItemEntry()
{
    Entry();
    for(int i = 0; i < MAX_FEATURES; i++) variance(i,i) = 1;
}


ItemEntry ItemEntry::createMeFrom(std::string line)
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
