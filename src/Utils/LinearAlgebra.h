#ifndef LINEARALGEBRA_H
#define LINEARALGEBRA_H

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <math.h>

// #define NDEBUG // uncomment to disable assert()
#include <cassert>

// Use (void) to silent unused warnings.
#ifndef assertm
#define assertm(exp, msg) assert(((void)msg, exp))
#endif


namespace linalg {
typedef std::vector< std::vector<double> > matrix;

static matrix getTranspose(matrix src) {
    assertm(!src.empty(), "Called linalg::transpose with empty matrix");

    matrix trans_vec(src[0].size(), std::vector<double>());

    for (int i = 0; i < src.size(); i++)
    {
        for (int j = 0; j < src[i].size(); j++)
        {
            trans_vec[j].push_back(src[i][j]);
        }
    }

    return trans_vec;
}

static std::vector<double> diagonal(matrix a){
    std::vector<double> retDiag;

    assertm(!a.empty(), "Called linalg::diagonal with empty matrix");

    int cols = a.size();
    int rows = a[0].size();

    assertm(cols == rows, "Cannot find diagonal in a non square matrix.");

    for(int i = 0; i < cols; i++){
        retDiag.push_back(a[i][i]);
    }

    return retDiag;
}

static double trace(matrix a){
    std::vector<double> v = diagonal(a);
    return std::accumulate(v.begin(), v.end(), 0);
}

static double getDeterminant(const matrix vect) {
    if(vect.size() != vect[0].size()) {
        throw std::runtime_error("Matrix is not quadratic");
    }
    int dimension = vect.size();

    if(dimension == 0) {
        return 1;
    }

    if(dimension == 1) {
        return vect[0][0];
    }

    //Formula for 2x2-matrix
    if(dimension == 2) {
        return vect[0][0] * vect[1][1] - vect[0][1] * vect[1][0];
    }

    double result = 0;
    int sign = 1;
    for(int i = 0; i < dimension; i++) {

        //Submatrix
        matrix subVect(dimension - 1, std::vector<double> (dimension - 1));
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

static matrix getCofactor(const matrix vect) {
    if(vect.size() != vect[0].size()) {
        throw std::runtime_error("Matrix is not quadratic");
    }

    matrix solution(vect.size(), std::vector<double> (vect.size()));
    matrix subVect(vect.size() - 1, std::vector<double> (vect.size() - 1));

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

static matrix getInverse(const matrix vect) {
    if(getDeterminant(vect) == 0) {
        throw std::runtime_error("Determinant is 0");
    }
    double d = 1.0/getDeterminant(vect);
    matrix solution(vect.size(), std::vector<double> (vect.size()));

    for(size_t i = 0; i < vect.size(); i++) {
        for(size_t j = 0; j < vect.size(); j++) {
            solution[i][j] = vect[i][j] * d;
        }
    }

    return getTranspose(getCofactor(solution));
}

static void printMatrix(const matrix vect) {
    for(std::size_t i = 0; i < vect.size(); i++) {
        for(std::size_t j = 0; j < vect[0].size(); j++) {
            std::cout << std::setw(8) << vect[i][j] << " ";
        }
        std::cout << "\n";
    }
}
}

#endif // LINEARALGEBRA_H
