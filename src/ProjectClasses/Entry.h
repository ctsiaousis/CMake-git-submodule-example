#ifndef ENTRY_H
#define ENTRY_H

#include "../Definitions.h"

class Entry{
    std::string id;
protected:
    eg::mat<MAX_FEATURES>      variance; // Var(Z)=Cov(Z,Z)
    eg::vec<MAX_FEATURES>      feature_means;
public:
    Entry();

    std::string getId() const;

    void setId(std::string newId);

    void setFeatures(std::vector<double> vecIn);

    Eigen::MatrixXd getFeatures();

    Eigen::MatrixXd getCovarianceMatrix(bool inverse = false);

    static Eigen::MatrixXd covarianceMat(Entry e1,Entry e2);

    static Eigen::MatrixXd meanMat(Entry e1,Entry e2);
};


#endif //ENTRY_H
