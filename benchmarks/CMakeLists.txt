
include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(benchmarks-formula-printer
   main.cpp 
)

target_link_libraries(benchmarks-formula-printer formula-printer)

install(
    PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/benchmarks-formula-printer
    DESTINATION bin
    RENAME ${CMAKE_PROJECT_NAME}-benchmarks
)
