# CMake 最低的版本要求
cmake_minimum_required(VERSION 3.10.0)

# 定义项目名称变量PROJECT_NAME, 默认值为demo
set(PROJECT_NAME demo)

# 项目名称以及版本
project(${PROJECT_NAME} VERSION 0.0.0)


################################################ Configuration ###################################################
# 设置C++的版本
set(CMAKE_CXX_STANDARD 14)

# 指定模式
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

###########################################################################################################

############################################## Tools ######################################################

# 当前目录下除了测试文件外所有的源文件的名称保存到 DIR_SRCS 变量
set(DIR_SRCS main.cpp)

# 包含头文件目录
include_directories(Basic)
include_directories(ThirdParty/include)

# 第三方链接库的目录
link_directories(ThirdParty/lib)

# 需要用到的第三方库
set(USED_TOOLS_LIB boost_regex)

# 添加子目录(工作目录的次一级子目录)
add_subdirectory(Basic)

# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})

# 链接第三方库
target_link_libraries(${PROJECT_NAME} ${USED_TOOLS_LIB})

# 链接项目产生的库
# target_link_libraries(${PROJECT_NAME} )

#############################################################################################################

################################################### Test ####################################################

# 包含测试部分的头文件目录
include_directories(Test)

# 添加子目录(次一级的测试目录)
add_subdirectory(Test) # 不用修改

# # 搜索当前工作目录下的所有源文件，并将这些源文件存在 DIR_SRCS 变量中
# aux_source_directory(. DIR_SRCS)

# 需要用到的第三方库
set(USED_TEST_LIB 
        gtest_main
        gtest
        pthread
        tools_test
    )

# 测试用例
set(TEST_CASES 
    test_
)

# 生成测试目标
add_executable(test_ test_.cpp)

# 链接第三方库
target_link_libraries(test_ ${USED_TEST_LIB})

###################################################################################################################


