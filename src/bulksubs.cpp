//
// Created by BVT.MI on 16.10.2022.
//

#include "bulkman.h"
#include <iostream>
#include "fstream"

namespace bvt {

    Report:: Report(Observable *lang) {
        lang->subscribe(this);
    }

    void Report:: update(const IBulkHandlerPtr b) {
        std::cout << "file print"  << std::endl;
 /*       std::ofstream a("bulk");
        a << "file print" << std::endl;
        a.close();
*/
//        std::ofstream a("bulk" + b.name());
//        a << b.output() << std::endl;
//        a.close();
    }

    UserInterface:: UserInterface(Observable *lang) {
        lang->subscribe(this);
    }

    void UserInterface:: update(const IBulkHandlerPtr b) {
        std::cout << "console print" << std::endl;
        std::cout << "bulk: " << b->output() << std::endl;
    }

}