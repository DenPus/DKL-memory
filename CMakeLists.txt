cmake_minimum_required(VERSION 2.8.9)
project(dkl-memory
        #[[VERSION 0.1.0]]
        LANGUAGES C
        )

set(CMAKE_C_STANDARD 11)

set(include_ls include/dkl-memory.h)
set(all_files
        header/main.h
        ${include_ls}
        src/now.c src/convert.c
        )
add_library(dkl-memory SHARED ${all_files})
#add_library(dkl-memory STATIC ${all_files})

target_include_directories(dkl-memory PRIVATE header)
target_include_directories(dkl-memory PUBLIC include)

set_target_properties(
        dkl-memory PROPERTIES
        PUBLIC_HEADER "${incude_ls}"
)

# example

add_executable(dkl-memory-now examples/now/main.c)
target_include_directories(dkl-memory-now PRIVATE include)
target_link_libraries(dkl-memory-now PRIVATE dkl-memory)

install(TARGETS dkl-memory
        PUBLIC_HEADER DESTINATION include
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )