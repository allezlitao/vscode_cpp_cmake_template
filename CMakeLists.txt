# CMake 最低的版本要求
cmake_minimum_required(VERSION 3.10.0)

# 定义项目名称变量PROJECT_NAME, 默认值为demo
set(PROJECT_NAME demo)

# 项目名称以及版本
project(${PROJECT_NAME} VERSION 0.1.0)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 设置C++的版本
set(CMAKE_CXX_STANDARD 14)

# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})

# 链接那些不是第三方库的库文件
target_link_libraries(${PROJECT_NAME} pthread)

##############################################################################################################
###################################     有关第三方库的使用     ###############################################

############################################## OpenCV ########################################################
# 设置OpenCVModule的路径
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/home/undefined/Downloads/opencv-3.4.1/build")
# 查找 OpenCV3.4.1的头文件和库文件路径以及库文件
find_package(OpenCV 3.4.1 REQUIRED)
# 包含OpenCV头文件目录
include_directories(${OpenCV_INCLUDE_DIRS})
message("OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
message("OpenCV_LIBS: ${OpenCV_LIBS}")
# 链接OpenCV库文件
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
##############################################################################################################

############################################## Boost #########################################################
# 查找 Boost_1_68_0的特定的库
find_package(Boost REQUIRED COMPONENTS regex)
# 包含Boost头文件目录
include_directories(${Boost_INCLUDE_DIRS})
message("Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message("Boost_LIBRARIES: ${Boost_LIBRARIES}")
# 链接Boost库文件
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
##############################################################################################################

############################################## OpenGL ########################################################
# opengl 头文件路径保存在 OPENGL_INC_DIR 变量
set(OPENGL_INC_DIR /usr/local/include /usr/include /usr/include/GL)
# opengl 链接库路径保存在 OPENGL_LDFLAGS 变量
set(OPENGL_LDFLAGS /usr/local/lib /usr/lib64)
# opengl 链接库名称保存在 OPENGL_LIBS 变量
set(OPENGL_LIBS GL GLU glut GLEW gltools glfw3 X11 Xxf86vm Xrandr pthread Xi dl Xinerama Xcursor m)
# OpenGL头文件目录
include_directories(${OPENGL_INC_DIR})
# OpenGL库文件目录
link_directories(${OPENGL_LDFLAGS})
# 链接OpenGL库文件
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBS})
###############################################################################################################

############################################# ZMQ #############################################################
# ZMQ 头文件路径保存在 ZMQ_INC_DIR 变量
set(ZMQ_INC_DIR /usr/local/include)
# ZMQ 链接库路径保存在 ZMQ_LDFLAGS 变量
set(ZMQ_LDFLAGS /usr/local/lib)
# ZMQ 链接库名称保存在 ZMQ_LIBS 变量
set(ZMQ_LIBS zmq)
# ZMQ 头文件目录
include_directories(${ZMQ_INC_DIR})
# ZMQ 库文件目录
link_directories(${ZMQ_LDFLAGS})
# 链接 ZMQ 库文件
target_link_libraries(${PROJECT_NAME} ${ZMQ_LIBS})
###############################################################################################################
