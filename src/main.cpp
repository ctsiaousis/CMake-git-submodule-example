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

    Eigen::MatrixXd  m1 = mUsers[100].getCovarianceMatrix(true);

    Eigen::MatrixXd  m2 = mItems[100].getCovarianceMatrix();

    Eigen::MatrixXd  test = m1 * m2 * m1;

    std::cout << test << std::endl;

    Eigen::MatrixXd t = mUsers[69].getFeatures();
    std::cout << t << std::endl;

    metric::KLDivergence(mUsers[50],mItems[50]);

    std::cout << std::endl<< std::endl<< std::endl;


    return 0;
}
