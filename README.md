# vscode + cmake 的cpp项目模板

> 软件实现跨平台，必须保证其能够在不同平台下编译。CMake允许开发者编译一种平台无关的CMakeLists.txt文件来制定整个编译流程，然后再根据目标用户的平台进一步生成所需的本地化的Makefile和工程文件，从而做到 `Write once, run everywhere`。

## Linux 平台

在linux平台使用CMake生成Makefile并编译的一般流程如下：

1. 编写CMake配置文件CMakeLists.txt;
2. 执行  `cmake PATH` 或者 `ccmake PATH` 生成Makefile。`PATH`是CMakeLists.txt所在目录， `cmake` 与 `ccmake` 的区别在于后者提供了一个交互界面;
3. 执行 `make -C PATH` 命令进行编译。 `-C` 表示到指定目录下执行make, `PATH` 为Makefile文件所在目录。在Makefile文件所在目录执行make命令，可以不需要带任何参数，直接执行 `make` 命令进行编译。
