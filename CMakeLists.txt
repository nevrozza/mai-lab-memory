cmake_minimum_required(VERSION 4.0)
project(mai_lab_memory C)

set(CMAKE_C_STANDARD 17)

add_executable(mai_lab_memory main.c
        vector/vector.c
        vector/vector.h
        client/client.c
        client/client.h
        utils/utils.h
        utils/utils.c
        solution/solution.c
        solution/solution.h
)
