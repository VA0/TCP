cmake_minimum_required(VERSION 3.10)
project(TCP) 

#Needed to have both libraries (.dll) and executable in the same place
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out CACHE STRING "" )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out CACHE STRING "" )


################
###SFML-2.5.1###
################
#Including CMakeLists.txt from SFML folder
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1)



############
###SERVER###
############
set (SRC server.cpp)  #setting source files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include) #including header files for SFML

add_executable(server ${SRC}) #creating executable
target_link_libraries(server sfml-network)  #linking library into executable

#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/test/SFML-2.5.1/lib/Debug)
#target_link_libraries(${PROJECT_NAME} -L${CMAKE_CURRENT_SOURCE_DIR}/test/SFML-2.5.1/lib/Debug)

set_target_properties(server PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON) #-std=C++17 is required



############
###CLIENT###
############
set (SRC client.cpp)  #setting source files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include) #including header files for SFML

add_executable(client ${SRC}) #creating executable
target_link_libraries(client sfml-network sfml-system)  #linking libraries into executable

set_target_properties(client PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON) #-std=C++17 is required




