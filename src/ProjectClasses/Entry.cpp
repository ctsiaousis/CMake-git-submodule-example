#include "Entry.h"


Entry::Entry()
{
    variance = linalg::matrix(MAX_FEATURES, std::vector<double>(MAX_FEATURES, 0));

    feature_means = linalg::matrix(MAX_FEATURES, std::vector<double>(MAX_FEATURES, 0));
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
        std::random_device rd{};
        std::mt19937 gen{rd()};
        // values near the mean are the most likely
        // standard deviation affects the dispersion of generated values from the mean
        std::normal_distribution<> d{vecIn.at(i), variance[0][0] != 0 ? variance[0][0] : 1 };
        for(int k = 0; k < MAX_FEATURES; k ++){
            feature_means[i][k] = d(gen);
        }
//        feature_means[i] = vecIn.at(i);
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
