#ifndef MYEIGENFUNCS_H
#define MYEIGENFUNCS_H

#include "Eigen"

namespace eg
{


    class MVnorm
    {
    public:
      MVnorm(const Eigen::VectorXd& mu,
          const Eigen::MatrixXd& s);;
      ~MVnorm();
      double pdf(const Eigen::VectorXd& x) const;
      Eigen::VectorXd sample(unsigned int nr_iterations = 20) const;
      Eigen::VectorXd mean;
      Eigen::MatrixXd sigma;
    };

};

#endif // MYEIGENFUNCS_H
