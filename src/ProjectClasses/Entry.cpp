#include "Entry.h"


Entry::Entry()
{
    norm_dist_space = (int) (NORM_DIST_END - NORM_DIST_START) / NORM_DIST_STEP;

    variance        = linalg::matrix(MAX_FEATURES, std::vector<double>(MAX_FEATURES,    0));
    feature_means   = linalg::matrix(MAX_FEATURES,std::vector<double >(norm_dist_space, 0));
//    std::cout << "Entry::Entry " << norm_dist_space << " - end\n";
}

std::string Entry::getId() const
{
    return id;
}

void Entry::setId(std::string newId)
{
    id = newId;
}

void Entry::setFeatures(std::vector<double> vecIn)
{
    assertm(vecIn.size() == MAX_FEATURES, "Entry::setFeatures - vector used is not complete");

//    std::cout << "Entry::setFeatures" << this;
    for(int i = 0; i < MAX_FEATURES; i++){
        int counter = 0;
        for(int x = 0; x < this->norm_dist_space; x ++){
            counter++;
            feature_means[i][x] = linalg::getNormDistByMathFormula(x, vecIn.at(i), variance[0][0] != 0 ? variance[0][0] : 1);
        }
//        std::cout << "Entry::setFeatures - counter " << counter;
    }
}

linalg::matrix Entry::getFeatures()
{
    return feature_means;
}

linalg::matrix Entry::getCovarianceMatrix(bool inverse){
    if(!inverse) return this->variance;

    return linalg::getInverse(this->variance);
}

///
/// \brief covarianceMat returns the Σ_{e1}^{-1}*Σ_{e2}
/// \param e1
/// \param e2
/// \return
///
linalg::matrix Entry::covarianceMat(Entry e1,Entry e2){

}

linalg::matrix Entry::meanMat(Entry e1,Entry e2){

}
