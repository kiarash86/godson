cmake_minimum_required(VERSION 3.16)

project(GODSON LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


target_include_directories(GODSON PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(GODSON
    main.cpp
    src/model/cards/bigTaha.cpp
    src/model/cards/card.cpp
    src/model/cards/danyGo.cpp
    src/model/cards/drWhite.cpp
    src/model/cards/littleTaha.cpp
    src/model/cards/protectorAmin.cpp

)

target_link_libraries(GODSON PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
