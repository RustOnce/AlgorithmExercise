##Project Name
project(AlgorithmExercise)
##Minimum cmake version
cmake_minimum_required(VERSION 3.10)
##Include files
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
##Souce code directory
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} Src)
##Link directories
link_directories(${CMAKE_CURRENT_LIST_DIR}/lib)
##Linked libraries
#target_link_libraries();
##Set CXX flags
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
set (CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS   "-Wall")                  # 开启所有警告
set (CMAKE_CXX_FLAGS_DEBUG   "-O0")
#set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG " )   # release包优化
##Executable file
add_executable(${PROJECT_NAME} ${Src})