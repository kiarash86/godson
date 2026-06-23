cmake_minimum_required(VERSION 3.16)
project(GODSON VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_executable(GODSON main.cpp ${SOURCES} ${HEADERS})
target_include_directories(GODSON PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)


target_link_libraries(GODSON PRIVATE ${CURSES_LIBRARIES})



find_package(Curses REQUIRED)
target_include_directories(GODSON PRIVATE ${CURSES_INCLUDE_DIRS})
target_link_libraries(GODSON PRIVATE ${CURSES_LIBRARIES})