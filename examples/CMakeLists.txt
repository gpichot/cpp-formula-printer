
include_directories(${CMAKE_SOURCE_DIR}/src)

file(
    GLOB
    usage_examples
    *.cpp
)

message(STATUS ${usage_examples})

foreach(file_example ${usage_examples})
    get_filename_component(example_name ${file_example} NAME_WE)
    add_executable(${example_name} ${file_example})
    target_link_libraries(${example_name} formula-printer)
    install(
        PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/${example_name}
        DESTINATION bin
        RENAME ${CMAKE_PROJECT_NAME}-${example_name}
    )
endforeach(file_example)
