//
// Created by BVT.MI on 16.10.2022.
//
#include <iostream>
#include "bulkman.h"

int main(int argc, char const *argv[]) {

    if (argc != 2) {
        std::cout << "Usage: bulk [bulk_size]" << std::endl;
        return 0;
    }

    bvt::BulkMan bulkMan(atoi(argv[1]));

    std::shared_ptr<bvt::Report> report0Ptr = bvt::Report::create(&bulkMan);
    report0Ptr->
            letsSubscibe(&bulkMan);
    std::shared_ptr<bvt::UserInterface> userInterface0Ptr = bvt::UserInterface::create(&bulkMan);
    userInterface0Ptr->
            letsSubscibe(&bulkMan);

    std::string line;
    while (std::cin >> line) {
        bulkMan.newString(line);
    }
    bulkMan.theEnd();
    return 0;

/*
    bvt::BulkMan bm(3);

    std::shared_ptr<bvt::Report> reportPtr = bvt::Report::create(&bm);
    reportPtr->
            letsSubscibe(&bm);
    std::shared_ptr<bvt::UserInterface> userInterfacePtr = bvt::UserInterface::create(&bm);
    userInterfacePtr->
            letsSubscibe(&bm);

    bm.newString("cmd1");
    bm.newString("cmd2");
    bm.newString("cmd3");
    bm.newString("cmd4");
    bm.newString("cmd5");
    bm.

            theEnd();

    std::cout << std::endl << "PART2" <<
              std::endl;

    bvt::BulkMan bm2(3);

    std::shared_ptr<bvt::Report> report2Ptr = bvt::Report::create(&bm2);
    report2Ptr->
            letsSubscibe(&bm2);
    std::shared_ptr<bvt::UserInterface> userInterface2Ptr = bvt::UserInterface::create(&bm2);
    userInterface2Ptr->
            letsSubscibe(&bm2);

    bm2.newString("cmd1");
    bm2.newString("cmd2");
    bm2.newString("{");
    bm2.newString("cmd3");
    bm2.newString("cmd4");
    bm2.newString("}");
    bm2.newString("{");
    bm2.newString("cmd5");
    bm2.newString("cmd6");
    bm2.newString("{");
    bm2.newString("cmd7");
    bm2.newString("cmd8");
    bm2.newString("}");
    bm2.newString("cmd9");
    bm2.newString("{");
    bm2.newString("cmd10");
    bm2.newString("cmd11");
    bm2.

            theEnd();

    return 0;
*/
}
