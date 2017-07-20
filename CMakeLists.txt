# CMakeLists.txt

cmake_minimum_required (VERSION 3.1 FATAL_ERROR)

project (leonhard)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

find_package (Boost 1.54.0 REQUIRED COMPONENTS
    program_options
    )

file (GLOB_RECURSE COMMON_SOURCES
    ./include/*.hpp
    ./src/*.cpp
    ./src/*.hpp
    )

add_executable (leonhard
    ${COMMON_SOURCES}
    )

target_link_libraries (leonhard
    ${Boost_LIBRARIES}
    )

target_include_directories (leonhard PUBLIC
    ./include
    ${Boost_INCLUDE_DIRS}
    )

target_compile_options (leonhard PUBLIC
    ${Boost_CFLAGS_OTHER}
    )

# vim:set sw=4 ts=4 et:
