cmake_minimum_required (VERSION 3.5)

project (libcolors VERSION 1.0)

# Variables
set (LIB_NAME "colors")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set (source_files src/Colors.cpp)

include (GenerateExportHeader)

add_library (${LIB_NAME} STATIC ${source_files})
target_include_directories (${LIB_NAME} PUBLIC include ${CMAKE_CURRENT_BINARY_DIR})

set_property (TARGET ${LIB_NAME} PROPERTY CXX_STANDARD 17)
generate_export_header (${LIB_NAME} BASE_NAME colors)
