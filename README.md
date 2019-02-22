# Project Template

> CMake的项目模板, 支持boost1.68, gtest, opencv这些第三方库;

## 项目结构说明

```shell

.
├── Basic
├── build
├── CMakeLists.txt
├── doc
├── main.cpp
├── README.md
├── Test
└── ThirdParty

```

+ Basic文件夹：存放着一些基础的源文件，不依赖于项目中的其它文件；

+ build文件夹：存放着编译生成的makefile文件，库文件，可执行文件等文件，这个文件夹不被git跟踪;

+ CMakeLists.txt: 是整个项目的编译规则；

+ doc: 存放着这个项目的配置文件，以及这个项目所有源文件的介绍文档；

+ main.cpp: 是整个项目的入口；

+ README.md: 是关于这个项目的介绍；

+ Test文件夹： 是用于存放测试内容的源文件，只需要在CMakeLists.txt添加源文件（去掉后缀），如果需要链接第三方库，也需要自己添加。

+ ThirdParty文件夹： 存放着项目引用的第三方库（boost, opencv, gtest），目的是实现与平台的低耦合。

当构建整个文件的时候，会同时构建项目以及测试；

至此，不打算继续维护它了，它的进一步开发在`Tools`这个项目中[https://github.com/AZMDDY/Tools.git](https://github.com/AZMDDY/Tools.git)