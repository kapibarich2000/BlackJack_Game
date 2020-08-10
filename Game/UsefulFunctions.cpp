#include "UsefulFunctions.h"
#include <iostream>

int EnterInt() {
    int number;
    while (1) {
        std::cin >> number;
        if (std::cin.fail()) { // Checking for entering a number
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout<<"Input error!\n";
            continue;
        }
        break;
    }
    return number;
}