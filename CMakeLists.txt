cmake_minimum_required(VERSION 3.5)

project(Chinese-Chess VERSION 0.1 LANGUAGES C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(
    GLOB_RECURSE
    SOURCE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*
)

file(
    GLOB_RECURSE
    HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*
)

file(
    GLOB_RECURSE
    UI
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/*
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(PROJECT_SOURCES

    ${SOURCE}
    ${HEADER}
    ${UI}

)

add_executable(Chinese-Chess
    ${PROJECT_SOURCES}
    )

