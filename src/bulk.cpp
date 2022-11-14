//
// Created by BVT.MI on 16.10.2022.
//
#include <iostream>
#include <unistd.h>
#include "bulkman.h"

int main(int argc, char const *argv[]) {
        std::cout << "Hello world" << std::endl;

        bvt::BulkMan bm(2);

        bvt::Report report{&bm};
        bvt::UserInterface ui{&bm};

        bm.set_language();
        sleep(2);
        bm.set_language();
    sleep(2);
    bm.set_language();
    sleep(2);
    bm.set_language();
    sleep(2);
    bm.set_language();
        return 0;

    }
