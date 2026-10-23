# 视觉第三课:VSCode和CMake

# 视觉第三课：vscode使用，cmake教学

可以按照先装工具，在跑一个小项目的顺序来学习，也就是先安装VScode并配置好C\+\+开发环境，然后通过一个简单项目来理解CMake的核心用法。



# 1\.安装VSCode与配置C\+\+开发环境

## 1\.1 安装VSCode

三种安装方法：

1\.使用apt下载（简单粗暴），先下载工具让apt支持通过HTTPS协议访问软件源。

```Plain Text
sudo apt install -y wget gpg apt-transport-https
```

然后下载密钥并把密钥放到系统目录。

```Plain Text
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
sudo install -D -o root -g root -m 644 packages.microsoft.gpg /etc/apt/keyrings/packages.microsoft.gpg
```

接着添加VSCode软件源

```Plain Text
echo "deb [arch=amd64 signed-by=/etc/apt/keyrings/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" | sudo tee /etc/apt/sources.list.d/vscode.list > /dev/null
```

最后更新一下源，直接下载

```Plain Text
sudo apt update
sudo apt install -y code
```

2\.去官网下载（稍微麻烦，但更范用），下载官方的安装包，然后在下载文件夹下打开终端输入

```Plain Text
sudo apt install ./你的安装包名字
```



3\.用snap下载（也简单但是然后产生环境隔离问题，我之前就遇到过，不推荐）

### 1\.1\.1 啥是VSCode

安装VSCode前，先知道什么是VSCode，干什么用的。VSCode全称Visual Studio Code，本质上是一个代码编辑器，而并非是传统意义的IDE（不过通过安装各种扩展，也可以获得类似IDE的体验）。

### 1\.1\.2 为啥选择VSCode

1\.轻量启动块

2\.扩展生态强大

3\.内置Git （下节课会提到）

4\.配置简单易懂

## 1\.2 安装编译器与CMake基础工具

### 1\.2\.1 编译器

编译器是一个把源代码翻译成机器码的程序，相当于是人和机器人之间的翻译官。

GCC：GNU Compiler Collection，GNU 编译器集合。它是一套编译器工具的总称，支持 C、C\+\+、Fortran、Go 等多种语言。

G\+\+：GCC 中专门编译 C\+\+ 的那个前端命令。

### 1\.2\.2 cmake

cmake是一个构建一整套程序的工具。当你项目大起来的时候，源文件几十上百个，还依赖各种库，你总不能都一个个g\+\+编译过来吧。这时候就需要cmake帮助你编译整个项目。你需要：写一个CMakeList\.txt，描述项目结构。然后cmake就会读取这个文件，助你编译。



所以这些都是必不可少的，使用下面这个代码下载一整套编译工具大礼包。

```Plain Text
sudo apt install -y build-essential cmake
```

# 2\.学习并快速简单上手CMake

## 2\.1 先写一个简单的代码

创建项目文件夹

```Plain Text
mkdir hello_cmake
```

新建文件，取个名字（“你的名字”\.cpp）写一个简单代码

```C++
#include <iostream>

int main() {
    std::cout << "Hello CMake!" << std::endl;
    return 0;
}
```

## 2\.2 编写CMakeLists\.txt

依旧新建文件，名字是 “CMakeLists\.txt” 然后写一下内容

```Plain Text
cmake_minimum_required(VERSION 3.10)  // cmake的所需最低版本
project(HelloCMake)                                      // 项目名称 

add_executable(hello main.cpp)                    // 程序名称以及源代码的名称
```

## 2\.3 进行cmake

打开终端，新建一个build文件夹（这是为了防止生成的一些cmake文件污染了源代码）然后进入build文件夹，打开终端输入

```Plain Text
cmake ..
make
```

不出问题的话应该就不会显示红色警告，然后输入\./hello 就可以看到输出了。



# 资源:

## 1\.[cmake官方文档](https://cmake.org/cmake/help/latest/)

## 2\.[VSCode官网](https://code.visualstudio.com/)



