cmake_minimum_required(VERSION 3.20)

#variables
set(Project_Name EntityComponentSystem)

project(${Project_Name})

#setting standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

#Generating Executable
add_executable(${Project_Name} src/main.cpp)