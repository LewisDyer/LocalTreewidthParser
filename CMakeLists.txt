cmake_minimum_required(VERSION 2.8.12)
project(LocalTreewidthParser)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/boost-treewidth)

add_executable(lg_parse lg_parser.cpp)
target_link_libraries(lg_parse ${CONAN_LIBS})