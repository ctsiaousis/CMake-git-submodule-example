#include "Definitions.h"
#include "CSVParser.h"
#include "Utils/Metrics.h"

int main()
{
    std::cout << "Hello World! " << USR_FILE_PATH << std::endl;

    std::vector<UserEntry> mUsers;
    mUsers = utils::parseCSVtoUsers();

    std::vector<ItemEntry> mItems;
    mItems = utils::parseCSVtoItems();

    for(const UserEntry &u : mUsers) {
        std::cout << u << std::endl;
    }
    for(const ItemEntry &i : mItems) {
        std::cout << i << std::endl;
    }

    linalg::matrix m1 = mUsers[100].getCovarianceMatrix(true);

    linalg::matrix m2 = mItems[100].getCovarianceMatrix();

    linalg::matrix test = linalg::multiply(m1, m2);

    linalg::printMatrix(test);

    linalg::matrix t = mUsers[69].getFeatures();
    linalg::printMatrix(t);

    metric::KLDivergence(mUsers[50],mItems[50]);

    std::cout << std::endl<< std::endl<< std::endl;

    linalg::matrix mTst = linalg::getTranspose(mUsers[30].getCovarianceMatrix(true));


    return 0;
}
