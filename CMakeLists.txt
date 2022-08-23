cmake_minimum_required(VERSION 3.17)
project(OpenGL)

set(CMAKE_CXX_STANDARD 14)

# 头文件路径配置
include_directories(./include) # 项目include目录
include_directories(/usr/local/include) # glfw默认安装目录

# 设置库文件目录
link_directories(/usr/local/lib) # glfw默认安装库目录

# 连接编译需要的系统框架
link_libraries("-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")

# 添加源文件
add_executable(OpenGL glad.c main.cpp)

# 链接glfw库
target_link_libraries(OpenGL glfw3)