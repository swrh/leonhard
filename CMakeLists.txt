# CMakeLists.txt

cmake_minimum_required (VERSION 3.1 FATAL_ERROR)

project (leonhard)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

file (GLOB_RECURSE COMMON_SOURCES
	./include/*.hpp
	./src/*.cpp
	./src/*.hpp
	)

add_executable (leonhard
	${COMMON_SOURCES}
	)

target_include_directories (leonhard PUBLIC
	./include
	)
