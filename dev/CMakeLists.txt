cmake_minimum_required(VERSION 3.5)

project(VtkPlayground LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(VTK
    REQUIRED vtk)

if (NOT VTK_FOUND)
    message("ABORT")
    return()
endif()
include(${VTK_USE_FILE})

add_executable(VtkPlayground main.cpp)

target_link_libraries(${PROJECT_NAME} ${VTK_LIBRARIES})
