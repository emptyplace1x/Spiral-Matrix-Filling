cmake_minimum_required(VERSION 3.23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(matrix_filling C)

set(SOURCES
    src/main.c 
    src/filling.c 
    src/generate.c 
    src/output.c
)

add_executable(matrix_filling ${SOURCES})

target_include_directories(matrix_filling
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
