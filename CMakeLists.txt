cmake_minimum_required(VERSION  3.10 FATAL_ERROR)

project(mainImage)

include(function.cmake)
add_subdirectory(ImageLib)

add_subdirectory(Picture)

option(BTEST "build test?" OFF)

if(BTEST)
    add_subdirectory(gtest)
    add_subdirectory(test)
endif()