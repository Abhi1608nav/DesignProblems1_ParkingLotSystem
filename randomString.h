#include <iostream>
#include <ctime>
#include <cstdlib>

std::string generateRandomString(int length) {
    static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string randomStr;
    randomStr.reserve(length);

    for (int i = 0; i < length; ++i) {
        randomStr += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return randomStr;
}


