
# Add all header files in include/controller
file(GLOB SYSTEM_HEADERS
    ${CMAKE_SOURCE_DIR}/include/System/*.h
)

# Add all source files in src/controller
file(GLOB SYSTEM_SOURCES
    ${CMAKE_SOURCE_DIR}/src/System/*.cpp
)

# Create the Controller library
add_library(System STATIC
    ${SYSTEM_HEADERS}
    ${SYSTEM_SOURCES}
)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

# Link libraries
target_link_libraries(System PUBLIC OpenGL::GL GLEW::GLEW glfw glm::glm)

# Include the header files in the library target
target_include_directories(System PUBLIC ${CMAKE_SOURCE_DIR}/include/System)

target_link_libraries(System PUBLIC Component Entity)