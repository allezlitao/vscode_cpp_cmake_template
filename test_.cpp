#include <iostream>
#include "test.hpp"
using namespace ToolsTest;

#define T_

int main(int argc, char **argv) {


#ifdef T_

#else
    std::cout << "Tools Test" << std::endl;
#endif // T_FM


    std::cout << "=======================================================================" << std::endl;
    return 0;
}