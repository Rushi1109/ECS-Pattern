
# Add all header files in include/controller
file(GLOB ENTITY_HEADERS
    ${CMAKE_SOURCE_DIR}/include/Entity/*.h
)

# Add all source files in src/controller
file(GLOB ENTITY_SOURCES
    ${CMAKE_SOURCE_DIR}/src/Entity/*.cpp
)

# Create the Controller library
add_library(Entity STATIC
    ${ENTITY_HEADERS}
    ${ENTITY_SOURCES}
)

# Include the header files in the library target
target_include_directories(Entity PUBLIC ${CMAKE_SOURCE_DIR}/include/Entity)

target_link_libraries(Entity PUBLIC Component)