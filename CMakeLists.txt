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
add_subdirectory(Test)

# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})

# 链接第三方库
target_link_libraries(${PROJECT_NAME} ${USED_TOOLS_LIB})

# 链接项目产生的库
# target_link_libraries(${PROJECT_NAME} )

#############################################################################################################
