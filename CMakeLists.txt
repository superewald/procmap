cmake_minimum_required(VERSION 3.5)
project(unstickymem VERSION 1.0 LANGUAGES CXX C)

# get list of source files
file(GLOB_RECURSE procmap_src relative ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp" "src/*c")
add_library(procmap SHARED ${procmap_src})

set_property(TARGET procmap PROPERTY POSITION_INDEPENDENT_CODE on)

target_compile_features(procmap PRIVATE cxx_std_14)

target_compile_options(procmap PRIVATE -Wall)
if(NOT WIN32)
	target_compile_options(procmap PRIVATE -g -Wshadow -pedantic -Wfatal-errors)
endif()

target_include_directories(procmap
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PUBLIC $<INSTALL_INTERFACE:include>
	PRIVATE src)

