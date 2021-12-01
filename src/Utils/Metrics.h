#ifndef METRTICS_H
#define METRTICS_H

#include "../ProjectClasses/UserEntry.h"
#include "../ProjectClasses/ItemEntry.h"

namespace metric {

static void KLDivergence(UserEntry usr, ItemEntry itm)
{
    linalg::matrix m1 = linalg::getLogOf(
                                linalg::multiply(  usr.getCovarianceMatrix(true) ,
                                                   itm.getCovarianceMatrix()));
    std::cout << " ----------------------------------------------------------------------------------------------------------------- " << std::endl;
    linalg::printMatrix(m1);
    linalg::elemWiseOperation(m1,'a');
    std::cout << " ----------------------------------------------------------------------------------------------------------------- " << std::endl;
    linalg::printMatrix(m1);
    linalg::elemWiseOperation(m1,'/',2);
    std::cout << " ----------------------------------------------------------------------------------------------------------------- " << std::endl;
    linalg::printMatrix(m1);

//    double secondTerm =
}

}

#endif // METRTICS_H
