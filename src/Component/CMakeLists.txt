
# Add all header files in include/controller
file(GLOB COMPONENT_HEADERS
    ${CMAKE_SOURCE_DIR}/include/Component/*.h
)

# Add all source files in src/controller
file(GLOB COMPONENT_SOURCES
    ${CMAKE_SOURCE_DIR}/src/Component/*.cpp
)

# Create the Controller library
add_library(Component STATIC
    ${COMPONENT_HEADERS}
    ${COMPONENT_SOURCES}
)

# Include the header files in the library target
target_include_directories(Component PUBLIC ${CMAKE_SOURCE_DIR}/include/Component)

target_link_libraries(Component PUBLIC Entity)