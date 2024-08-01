cmake_minimum_required(VERSION 3.20)

#variables
set(Project_Name EntityComponentSystem)

project(${Project_Name})

#setting standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(src/Component)
add_subdirectory(src/Entity)
add_subdirectory(src/System)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Generate executable
add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC Entity Component System)