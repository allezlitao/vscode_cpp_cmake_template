# vscode + cmake 的 C++ 项目模板

> 软件实现跨平台，必须保证其能够在不同平台下编译。CMake允许开发者编译一种平台无关的CMakeLists.txt文件来制定整个编译流程，然后再根据目标用户的平台进一步生成所需的本地化的Makefile和工程文件，从而做到 `Write once, run everywhere`。

## Linux 平台(Linux Mint 19)

```shell
# 安装必须的包
$ sudo apt-get install build-essential
$ sudo apt-get install cmake git gcc g++
```

在linux平台使用CMake生成Makefile并编译的一般流程如下：

1. 编写CMake配置文件CMakeLists.txt;
2. 执行  `cmake PATH` 或者 `ccmake PATH` 生成Makefile。`PATH`是CMakeLists.txt所在目录， `cmake` 与 `ccmake` 的区别在于后者提供了一个交互界面;
3. 执行 `make -C PATH` 命令进行编译。 `-C` 表示到指定目录下执行make, `PATH` 为Makefile文件所在目录。在Makefile文件所在目录执行make命令，可以不需要带任何参数，直接执行 `make` 命令进行编译。

在Linux平台使用VSCode开发：

VSCode必要的插件：

+ C/C++
+ C++ Intellisense
+ CMake
+ CMake Tools
+ CMake Tools Helper
+ GitLens


项目模板的项目树：
```shell
.
└── .vscode
│   ├── c_cpp_properties.json
│   └── settings.json
├── build
├── CMakeLists.txt
├── .gitignore
├── main.cpp
├── README.md
```

+ `.vscode`文件中包含了关于VSCode编辑器的一些配置文件。
+ `c_cpp_properties.json`文件中主要是配置头文件查找路径，当使用到第三方库，比如Boost,OpenCV等，就需要在这个文件中添加这些库的头文件路径。
+ `setting.json`文件对当前的工程进行了一些配置。
+ `build`是cmake构建工程是产生的，里面包含了cmake产生的所有内容，这是使用VSCode的好处，直接执行`cmake .`，cmake文件将直接分散到整个工程中，不利于项目的管理。
+ `CMakeLists.txt`是整个工程的核心，它定义了整个工程的编译流程。

使用介绍：

![image_1cttvicc233u1m1q3m912uq1vha19.png-256.5kB][1]

`master*`表明当前处于master分支；
`CMake: Debug: Ready`：表明你选择了构建类型为`Debug`；
`GCC 7.3.0`: 表明你选择了`GCC 7.3.0`作为你的编译器；
`Build: [all]` ：表明可以构建所有可用的目标，点击`Build`你将会构建所有可用的目标；
`Debug demo`： 点击`Debug`，你将运行调试demo；

这里的项目使用三个库，分别是Boost,OpenCV,OpenGL，有关它们的安装配置教程如下：

Boost安装使用方法：[https://blog.csdn.net/qq_34347375/article/details/83589704](https://blog.csdn.net/qq_34347375/article/details/83589704)

OpenCV安装使用方法：[https://blog.csdn.net/qq_34347375/article/details/81137142](https://blog.csdn.net/qq_34347375/article/details/81137142)

OpenGL安装使用方法：[https://blog.csdn.net/qq_34347375/article/details/83575897](https://blog.csdn.net/qq_34347375/article/details/83575897)

 [1]: http://static.zybuluo.com/azmddy/db5wyqz0woxx0ndnk2wqx003/image_1cttvicc233u1m1q3m912uq1vha19.png