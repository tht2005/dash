cmake_minimum_required(VERSION 3.16)

project(dash VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_FILES   src/main.c
                src/job.c
    )

add_executable(dash ${SRC_FILES})

target_include_directories(
    dash PUBLIC
    "${PROJECT_BINARY_DIR}/include"
    "${PROJECT_SOURCE_DIR}/include"
)

configure_file(
    include/config.h.in
    include/config.h
    @ONLY
)
