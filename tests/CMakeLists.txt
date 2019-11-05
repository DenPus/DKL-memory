file(GLOB C_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
add_custom_target(dkl-mem-tests)

# Dependencies

# -- dtest

if (NOT TARGET dtest AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/lib/dtest/CMakeLists.txt")
    add_subdirectory(lib/dtest)
endif()

if (TARGET dtest)
    link_libraries(dtest)
endif()

include_directories(
    ../lib/dtest/include/dtest
    ../lib/dtest/include
    ../lib/dtest
    )

include_directories(../headers)

foreach (module ${C_FILES})
    get_filename_component(name ${module} NAME_WE)
    set(libname dkl-mem-ts-${name})
    add_library(${libname} SHARED ${module})
    target_link_libraries(${libname} PRIVATE dkl-mem)
    add_dependencies(dkl-mem-tests ${libname})
endforeach ()
