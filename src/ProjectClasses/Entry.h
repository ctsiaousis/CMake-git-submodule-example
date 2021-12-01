#ifndef ENTRY_H
#define ENTRY_H

#include "../Definitions.h"

class Entry{
    std::string id;
protected:
    linalg::matrix variance; // Var(Z)=Cov(Z,Z)
    linalg::matrix feature_means;
public:
    Entry();

    std::string getId() const;

    void setId(std::string newId);

    void setFeatures(std::vector<double> vecIn);

    linalg::matrix getFeatures();

    linalg::matrix getCovarianceMatrix(bool inverse = false);

    static linalg::matrix covarianceMat(Entry e1,Entry e2);

    static linalg::matrix meanMat(Entry e1,Entry e2);
};


#endif //ENTRY_H
