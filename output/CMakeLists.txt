cmake_minimum_required(VERSION 3.5)

project(uaserver LANGUAGES CXX C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#交叉编译选项
set(pitools ${CMAKE_SOURCE_DIR}/../arm-linux-gnueabihf)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# set(CMAKE_SYSROOT /home/devel/rasp-pi-rootfs)
# set(CMAKE_STAGING_PREFIX /home/devel/stage)

set(CMAKE_C_COMPILER ${pitools}/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${pitools}/bin/arm-linux-gnueabihf-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
#交叉编译选项


add_executable(uaserver main.cpp myUAModel.cpp open62541.c)
