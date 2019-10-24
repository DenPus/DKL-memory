cmake_minimum_required(VERSION 2.8.9)
project(dkl-mem LANGUAGES C)

set(CMAKE_C_STANDARD 11)

file(GLOB src_ls "src/*.c")
file(GLOB include_ls "include/*.h" "include/dkl-mem/*.h")

install(DIRECTORY include DESTINATION include)

add_library(dkl-mem ${include_ls} ${src_ls})

link_libraries(dkl-memory)
include_directories(header include include/dkl-mem)

set_target_properties(
        dkl-mem PROPERTIES
        PUBLIC_HEADER "${incude_ls}"
)

install(TARGETS dkl-mem
        PUBLIC_HEADER DESTINATION include
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )

link_libraries(dkl-mem)

if (NOT exd_examples)
    add_subdirectory(examples)
endif ()

if (NOT exd_tests)
    add_subdirectory(tests)
endif ()
