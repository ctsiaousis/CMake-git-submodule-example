#include "Entry.h"


Entry::Entry()
{
    variance = linalg::matrix(MAX_FEATURES, std::vector<double>(MAX_FEATURES, 0));

    feature_means = std::vector<double>(MAX_FEATURES, 0);
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

    for(int i = 0; i < MAX_FEATURES; i++){
        feature_means[i] = vecIn.at(i);
    }
}

std::vector<double> Entry::getFeatures()
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
