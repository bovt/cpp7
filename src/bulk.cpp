//
// Created by BVT.MI on 16.10.2022.
//
#include <iostream>
#include <unistd.h>
#include "bulkman.h"

int main(int argc, char const *argv[]) {
        std::cout << "Hello world" << std::endl;

        bvt::BulkMan bm(3);

        bvt::Report report{&bm};
        bvt::UserInterface ui{&bm};

        bm.newString("cmd1");
        bm.newString("cmd2");
        bm.newString("cmd3");
        bm.newString("cmd4");
        bm.newString("cmd5");
        bm.theEnd();

    std::cout << std::endl << "PART2" << std::endl;


    bvt::BulkMan bm2(3);

        bvt::Report report2{&bm2};
        bvt::UserInterface ui2{&bm2};

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
    bm2.theEnd();

    return 0;

    }
