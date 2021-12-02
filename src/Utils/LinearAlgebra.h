#ifndef LINEARALGEBRA_H
#define LINEARALGEBRA_H

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <random>
#include <vector>
#include <math.h>

#include "Eigen/Core"
#include "Eigen/Dense"

// #define NDEBUG // uncomment to disable assert()
#include <cassert>

// Use (void) to silent unused warnings.
#ifndef assertm
#define assertm(exp, msg) assert(((void)msg, exp))
#endif


namespace linalg {

template <class T>
using mat = std::vector< std::vector<T> >  ;

typedef mat<double>                                  matrix;
typedef mat< std::normal_distribution< double > >    mvarnorm;

static mat<double> getTranspose(mat<double> src);
static std::vector<double> getDiagonal(mat<double> a);
static double trace(mat<double> a);
static double sumOf(mat<double> a);
static double getDeterminant(const mat<double> vect);
static mat<double> getCofactor(const mat<double> vect);
static mat<double> getInverse(const mat<double> vect);
static mat<double> multiply(mat<double> a, mat<double> b);
static void printMatrix(const mat<double> vect);
static void printVector(const std::vector<double> vect);
static mat<double> getLogOf(mat<double> src); //TODO: Implement this func
static void elemWiseOperation(mat<double> &src, char o, int scalar = -1);
static mat<double> elemWiseOperation(mat<double> m1, char o, mat<double> m2);
static bool isMatrixDiagonal(mat<double> src);
static double getNormDistByMathFormula(double x, double m = 0, double var = 1);




////////////////////////////////////////////////// IMPLEMENTATIONS //////////////////////////////////////////////////


void printVector(const std::vector<double> vect) {
    std::cout << "[ ";
    for(std::size_t i = 0; i < vect.size(); i++) {
        std::cout << vect[i] << ((i < vect.size()-1)?" , ":" ");
    }
    std::cout << "] \n";
}

mat<double> elemWiseOperation(mat<double> m1, char o, mat<double> m2) {
    if(m1.size() != m2.size() || m1.empty() || m2.empty())
        throw std::runtime_error("linalg::elemWiseOperation - mat<double> sizes are not the same or are zero");

    mat<double> retMat = mat<double>(m1.size(),std::vector<double>(m1[0].size(),0));

    switch (o) {
    case '+':{
        for(int i = 0; i < m1.size(); i++){
            if(m1[i].size()!=m2[i].size()){
                throw std::runtime_error("linalg::elemWiseOperation - mat<double> sizes are not the same");
            }
            for(int k = 0; k < m1[i].size(); k ++){
                retMat[i][k] = m1[i][k] + m2[i][k];
            }
        }
        break;
    }
    case '-':{
        for(int i = 0; i < m1.size(); i++){
            if(m1[i].size()!=m2[i].size()){
                throw std::runtime_error("linalg::elemWiseOperation - mat<double> sizes are not the same");
            }
            for(int k = 0; k < m1[i].size(); k ++){
                retMat[i][k] = m1[i][k] - m2[i][k];
            }
        }
        break;
    }
    case '*':{
        for(int i = 0; i < m1.size(); i++){
            if(m1[i].size()!=m2[i].size()){
                throw std::runtime_error("linalg::elemWiseOperation - mat<double> sizes are not the same");
            }
            for(int k = 0; k < m1[i].size(); k ++){
                retMat[i][k] = m1[i][k] * m2[i][k];
            }
        }
        break;
    }
    case '/':{
        for(int i = 0; i < m1.size(); i++){
            if(m1[i].size()!=m2[i].size()){
                throw std::runtime_error("linalg::elemWiseOperation - mat<double> sizes are not the same");
            }
            for(int k = 0; k < m1[i].size(); k ++){
                retMat[i][k] = m1[i][k] / m2[i][k];
            }
        }
        break;
    }
    default:

        break;
    }
    return retMat;
}

void elemWiseOperation(mat<double> &src, char o, int scalar) {
    switch (o) {
    case '+':{
        auto func = [scalar](double &c) -> double{ return c+scalar; };
        for(int i = 0; i < src.size(); i++)
            std::transform(src[i].begin(), src[i].end(), src[i].begin(), func);
        break;
    }
    case '-':{
        auto func = [scalar](double &c) -> double{ return c-scalar; };
        for(int i = 0; i < src.size(); i++)
            std::transform(src[i].begin(), src[i].end(), src[i].begin(), func);
        break;
    }
    case '*':{
        auto func = [scalar](double &c) -> double{ return c*scalar; };
        for(int i = 0; i < src.size(); i++)
            std::transform(src[i].begin(), src[i].end(), src[i].begin(), func);
        break;
    }
    case '/':{
        auto func = [scalar](double &c) -> double{ return c/scalar; };
        for(int i = 0; i < src.size(); i++)
            std::transform(src[i].begin(), src[i].end(), src[i].begin(), func);
        break;
    }
    case 'a':{
        auto func = [](double &c) -> double{ return abs(c); };
        for(int i = 0; i < src.size(); i++)
            std::transform(src[i].begin(), src[i].end(), src[i].begin(), func);
        break;
    }
    case 'l':{
        auto func = [](double &c) -> double{ return log(c); };
        for(int i = 0; i < src.size(); i++)
            std::transform(src[i].begin(), src[i].end(), src[i].begin(), func);
        break;
    }
    default:

        break;
    }
}

bool isMatrixDiagonal(mat<double> src) {
    for(int i = 0; i < src.size(); i++){
        for(int k = 0; k < src[i].size(); k++){
            if(k == i) continue;
            if(src[i][k] != 0) return false;
        }
    }
    return true;
}

mat<double> getTranspose(mat<double> src) {
    assertm(!src.empty(), "Called linalg::transpose with empty mat<double>");

    mat<double> trans_vec(src[0].size(), std::vector<double>());

    for (int i = 0; i < src.size(); i++)
    {
        for (int j = 0; j < src[i].size(); j++)
        {
            trans_vec[j].push_back(src[i][j]);
        }
    }

    return trans_vec;
}

mat<double> getLogOf(mat<double> src) { //TODO: Implement this func
    assertm(!src.empty(), "Called linalg::getLogOf with empty mat<double>");

    if(isMatrixDiagonal(src)){
        elemWiseOperation(src, 'l');
    }else{
        throw std::runtime_error("mat<double> log not implemented for non diagonal matricies");
    }
    return src;
}

std::vector<double> getDiagonal(mat<double> a){
    std::vector<double> retDiag;

    assertm(!a.empty(), "Called linalg::diagonal with empty mat<double>");

    int cols = a.size();
    int rows = a[0].size();

    assertm(cols == rows, "Cannot find diagonal in a non square mat<double>.");

    for(int i = 0; i < cols; i++){
        retDiag.push_back(a[i][i]);
    }

    return retDiag;
}

double trace(mat<double> a){
    std::vector<double> v = getDiagonal(a);
    return std::accumulate(v.begin(), v.end(), 0);
}

double sumOf(mat<double> a){
    double sum = 0;
    for(int i = 0; i < a.size(); i++){
        std::vector<double> v = a[i];
        sum += std::accumulate(v.begin(), v.end(), 0);;
    }
    return sum;
}

double getDeterminant(const mat<double> vect) {
    if(vect.size() != vect[0].size()) {
        throw std::runtime_error("mat<double> is not quadratic");
    }
    int dimension = vect.size();

    if(dimension == 0) {
        return 1;
    }

    if(dimension == 1) {
        return vect[0][0];
    }

    //Formula for 2x2-mat<double>
    if(dimension == 2) {
        return vect[0][0] * vect[1][1] - vect[0][1] * vect[1][0];
    }

    double result = 0;
    int sign = 1;
    for(int i = 0; i < dimension; i++) {

        //Submat<double>
        mat<double> subVect(dimension - 1, std::vector<double> (dimension - 1));
        for(int m = 1; m < dimension; m++) {
            int z = 0;
            for(int n = 0; n < dimension; n++) {
                if(n != i) {
                    subVect[m-1][z] = vect[m][n];
                    z++;
                }
            }
        }

        //recursive call
        result = result + sign * vect[0][i] * getDeterminant(subVect);
        sign = -sign;
    }

    return result;
}

mat<double> getCofactor(const mat<double> vect) {
    if(vect.size() != vect[0].size()) {
        throw std::runtime_error("mat<double> is not quadratic");
    }

    mat<double> solution(vect.size(), std::vector<double> (vect.size()));
    mat<double> subVect(vect.size() - 1, std::vector<double> (vect.size() - 1));

    for(std::size_t i = 0; i < vect.size(); i++) {
        for(std::size_t j = 0; j < vect[0].size(); j++) {

            int p = 0;
            for(size_t x = 0; x < vect.size(); x++) {
                if(x == i) {
                    continue;
                }
                int q = 0;

                for(size_t y = 0; y < vect.size(); y++) {
                    if(y == j) {
                        continue;
                    }

                    subVect[p][q] = vect[x][y];
                    q++;
                }
                p++;
            }
            solution[i][j] = pow(-1, i + j) * getDeterminant(subVect);
        }
    }
    return solution;
}

mat<double> getInverse(const mat<double> vect) {
    if(getDeterminant(vect) == 0) {
        throw std::runtime_error("Determinant is 0");
    }
    double d = 1.0/getDeterminant(vect);
    mat<double> solution(vect.size(), std::vector<double> (vect.size()));

    for(size_t i = 0; i < vect.size(); i++) {
        for(size_t j = 0; j < vect.size(); j++) {
            solution[i][j] = vect[i][j] * d;
        }
    }

    return getTranspose(getCofactor(solution));
}

void printMatrix(const mat<double> vect) {

    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
    for(std::size_t i = 0; i < vect.size(); i++) {
        for(std::size_t j = 0; j < vect[0].size(); j++) {
            std::cout << std::setw(12) << vect[i][j] << " ";
        }
        std::cout << "\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
    }
}

mat<double> multiply(mat<double> a, mat<double> b)
{
    const int n = a.size();     // a rows
    const int m = a[0].size();  // a cols
    const int p = b[0].size();  // b cols

    mat<double> c(n, std::vector<double>(p, 0));
    for (auto j = 0; j < p; ++j)
    {
        for (auto k = 0; k < m; ++k)
        {
            for (auto i = 0; i < n; ++i)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}


double getNormDistByMathFormula( double x, double m, double var){
    double first = 1/(sqrtf(2*M_PI*var*var));
    double pwr   = -( powf(x-m,2)/(2*var*var));
    return first * powf(M_E, pwr);
}


class Mvn
{
public:
  Mvn(const Eigen::VectorXd& mu,
      const Eigen::MatrixXd& s);
  ~Mvn();
  double pdf(const Eigen::VectorXd& x) const;
  Eigen::VectorXd sample(unsigned int nr_iterations = 20) const;
  Eigen::VectorXd mean;
  Eigen::MatrixXd sigma;
};


}

#endif // LINEARALGEBRA_H
