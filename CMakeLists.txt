
# CMake 最低的版本要求
cmake_minimum_required(VERSION 3.12)

# 项目名称
project(demo)

# 添加版本号
set(demo_VERSION_MAJOR 0)
set(demo_VERSION_MINOR 0)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
 
# opencv 头文件路径保存在 OPENCV_INC_DIR
set(OPENCV_INC_DIR /usr/local/include/opencv /usr/local/include/opencv2)
# opencv 链接库路径
set(OPENCV_LDFLAGS /usr/local/lib)
# opencv 链接库
set(OPENCV_LIBS opencv_calib3d opencv_core opencv_dnn opencv_features2d opencv_flann opencv_highgui opencv_imgcodecs opencv_imgproc opencv_ml opencv_objdetect opencv_photo opencv_shape opencv_stitching opencv_superres opencv_video opencv_videoio opencv_videostab)


# 第三方库的头文件目录
include_directories(${OPENCV_INC_DIR})

# 第三方库的动态链接库目录
link_directories(${OPENCV_LDFLAGS})

# 第三方库
link_libraries(${OPENCV_LIBS})

# 设置C++的版本
set(CMAKE_CXX_STANDARD 14)

# 指定生成目标
add_executable(demo ${DIR_SRCS})
