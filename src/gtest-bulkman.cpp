//
// Created by BVT.MI on 12.11.2022.
//

#include <../googletest/include/gtest/gtest.h>
#include <string>
#include "bulkman.h"

TEST(GOOGLE_TEST1, test1) {
    bvt::BulkMan man(2);
    man.newString("1");
    man.newString("2");
    ASSERT_TRUE(man.getBulkSize() == 0);
}

TEST(GOOGLE_TEST1, test2) {
    bvt::BulkMan man(7);
    man.newString("1");
    man.newString("2");
    man.newString("{");
//std::cout << "man.getBulkSize()"  << man.getBulkSize() << std::endl;
    ASSERT_TRUE(man.getBulkSize() == 0);
}

TEST(GOOGLE_TEST1, test3) {
    bvt::BulkMan man(3);
    man.newString("1");
    man.newString("2");
    std::cout << "man.getBulkOutput()" << man.getBulkOutput() << std::endl;
    ASSERT_TRUE(man.getBulkOutput() == "1, 2");
}

TEST(GOOGLE_TEST1, test4) {
    bvt::BulkMan man(6);
    man.newString("{");
    man.newString("2");
    man.newString("{");
    man.newString("2");
    man.newString("{");
    man.newString("2");
    ASSERT_TRUE(man.getBulkSize() == 3);
    ASSERT_TRUE(man.getBulkOutput() == "2, 2, 2");
}

TEST(GOOGLE_TEST1, test5) {
    bvt::BulkMan man(6);
    man.newString("{");
    man.newString("2");
    man.newString("{");
    man.newString("2");
    man.newString("{");
    man.newString("2");
    man.newString("}");
    man.newString("}");
    ASSERT_TRUE(man.getBulkSize() == 3);
    ASSERT_TRUE(man.getBulkOutput() == "2, 2, 2");
}

TEST(GOOGLE_TEST1, test6) {
    bvt::BulkMan man(6);
    man.newString("{");
    man.newString("2");
    man.newString("{");
    man.newString("2");
    man.newString("{");
    man.newString("2");
    man.newString("}");
    man.newString("}");
    man.newString("}");
    ASSERT_TRUE(man.getBulkSize() == 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
