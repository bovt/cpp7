//
// Created by BVT.MI on 16.10.2022.
//

#include "bulkman.h"
#include <iostream>
#include "fstream"

namespace bvt {

    Report::Report(Observable *observable) {
    }

    void Report::update(std::string bulkOutput, std::string bulkName) {
        std::ofstream a("bulk" + bulkName);
        a << "bulk: " << bulkOutput << std::endl;
        a.close();
    }

    UserInterface::UserInterface(Observable *observable) {
    }

    void UserInterface::update(std::string bulkOutput, std::string bulkName) {
        std::cout << "bulk: " << bulkOutput << std::endl;
    }

}