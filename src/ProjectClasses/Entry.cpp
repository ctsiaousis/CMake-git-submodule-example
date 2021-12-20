#include "Entry.h"


Entry::Entry()
{
    variance        = eg::mat<MAX_FEATURES>::Zero();
    feature_means   = eg::vec<MAX_FEATURES>::Zero();
//    std::cout << "Entry::Entry - var \n" << variance << " - end\n\n";
//    std::cout << "Entry::Entry - fea \n" << feature_means << " - end\n";
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
        feature_means(i,0) = vecIn.at(i);
    }
}

Eigen::MatrixXd Entry::getFeatures()
{
    return feature_means;
}

Eigen::MatrixXd Entry::getCovarianceMatrix(bool inverse){
    if(!inverse) return this->variance;

    return this->variance.inverse();
}

///
/// \brief covarianceMat returns the Σ_{e1}^{-1}*Σ_{e2}
/// \param e1
/// \param e2
/// \return
///
Eigen::MatrixXd Entry::covarianceMat(Entry e1,Entry e2){

}

Eigen::MatrixXd Entry::meanMat(Entry e1,Entry e2){

}
