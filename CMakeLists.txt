#### Setup Directories ####
#Main output directory
cmake_minimum_required(VERSION 4.3)
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
# Ouput all DLLs from all libs into main build folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

#### Add External Dependencies ####
add_subdirectory("lib/SFML-2.6.2")
set(SFML_INCS "lib/SFML-2.6.2/include")
link_directories("${CMAKE_BINARY_DIR}/lib/SFML-2.6.2/lib")
add_custom_target(copy_resources ALL COMMAND ${CMAKE_COMMAND} 
  -E copy_directory
    "${PROJECT_SOURCE_DIR}/resources"
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources
)
#### level system ####
#add_library(tile_level STATIC tile_level_loader/level_system.cpp)
#target_include_directories(tile_level INTERFACE tile_level_loader)
#target_link_libraries(tile_level sfml-graphics)

#### Practical 1 ####
add_executable(pacman main.cpp)
target_include_directories(pacman PRIVATE ${SFML_INCS})
target_link_libraries(pacman sfml-graphics)

set_target_properties(pacman 
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
)

add_dependencies(pacman copy_resources)