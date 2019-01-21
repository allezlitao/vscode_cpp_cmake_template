#include <iostream>
#include "gtest/gtest.h"
#include "test.hpp"
using namespace ToolsTest;

#define T_

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);

#ifdef T_

#else
    std::cout << "Tools Test" << std::endl;
#endif // T_FM


    std::cout << "=======================================================================" << std::endl;
    return RUN_ALL_TESTS();
}