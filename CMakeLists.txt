cmake_minimum_required(VERSION 3.16)

project(misowa)

add_executable(misowa src/main.cpp)

target_include_directories(misowa PRIVATE include)
target_link_libraries(misowa glfw)