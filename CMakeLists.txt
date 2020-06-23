cmake_minimum_required(VERSION 3.13)
project(MapleLCMDistChronoBT)

set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_SOURCE_DIR}")


aux_source_directory(utils DIR_LIB_SRCS)
aux_source_directory(simp MAIN)

add_library(utils
        ${DIR_LIB_SRCS}
        )

find_package(ZLIB)
if (ZLIB_FOUND)
    #    target_include_directories(clib PRIVATE ${ZLIB_INCLUDE_DIR})
    #    target_link_libraries(curltest ${ZLIB_LIBRARY})
    message(" -- find zlib lib path:" ${ZLIB_LIBRARY})
    message(" -- find zlib include path:" ${ZLIB_INCLUDE_DIR})
    target_link_libraries(utils ${ZLIB_LIBRARY})
    target_include_directories(utils PRIVATE ${ZLIB_INCLUDE_DIR})
else (ZLIB_FOUND)
    message(FATAL_ERROR ”ZLIB library not found”)
endif (ZLIB_FOUND)


add_library(core
        core/Main.cc
        core/Solver.cc
        )

add_executable(testmain main.cc)
target_link_libraries(testmain ${ZLIB_LIBRARY})


add_executable(starexec_run_default ${MAIN})
target_link_libraries(starexec_run_default utils core)

