#include "Definitions.h"
#include "CSVParser.h"

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
    return 0;
}
