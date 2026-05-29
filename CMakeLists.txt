cmake_minimum_required(VERSION 3.16)

project(GODSON LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GODSON
    main.cpp
    src/model/cards/bigTaha.cpp
    src/model/cards/card.cpp
    src/model/cards/danyGo.cpp
    src/model/cards/drWhite.cpp
    src/model/cards/littleTaha.cpp
    src/model/cards/protectorAmin.cpp
    src/model/abilities/sharpBlade.cpp
)

target_include_directories(GODSON PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
