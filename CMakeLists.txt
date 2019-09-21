cmake_minimum_required(VERSION 2.8.9)
project(dkl-memory
        #[[VERSION 0.1.1.0]]
        LANGUAGES C
        )

set(CMAKE_C_STANDARD 11)
#[[set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpic --static")]]

set(include_ls include/dkl-memory.h)
set(all_files
        header/main.h
        ${include_ls}
        src/now.c src/convert.c
        )
add_library(dkl-memory STATIC ${all_files})
#add_library(dkl-memory STATIC ${all_files})

include_directories(dkl-memory header include)

set_target_properties(
        dkl-memory PROPERTIES
        PUBLIC_HEADER "${include_ls}"
)

install(TARGETS dkl-memory
        PUBLIC_HEADER DESTINATION include
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )

add_subdirectory(examples)
add_subdirectory(tests)
