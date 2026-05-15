cmake_minimum_required(VERSION 3.16)

project(misowa)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SRC_FILES
    src/*.cpp
)

add_executable(
    misowa

    cmd/main.cpp

    ${SRC_FILES}

    vendor/glad.c
)

target_include_directories(
    misowa
    PRIVATE

    include
)

if(WIN32)
    target_link_libraries(
        misowa

        glfw3
        opengl32
    )
else()
    target_link_libraries(
        misowa

        glfw3
        OpenGL::GL
    )
endif()

install(TARGETS misowa DESTINATION .)

set(CPACK_PACKAGE_NAME "Misowa")
set(CPACK_PACKAGE_VENDOR "Misowa Studio")
set(CPACK_PACKAGE_VERSION "1.0.0")

set(CPACK_PACKAGE_FILE_NAME "MisowaInstaller")

set(CPACK_GENERATOR "NSIS")

include(CPack)