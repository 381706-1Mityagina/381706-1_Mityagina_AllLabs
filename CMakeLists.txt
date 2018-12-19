cmake_minimum_required(VERSION 2.8) 

set(PROJECT_NAME AllLabs) 
project(${PROJECT_NAME}) 

set (ListLib ListLib)

set (StackList StackList)
set(StackListLib StackListLib) 
set (StackListTests StackListTests)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)  
if(NOT CMAKE_BUILD_TYPE) 
  set(CMAKE_BUILD_TYPE Release) 
endif()

file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 


#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
add_subdirectory(ListLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
add_subdirectory(StackList)
add_subdirectory(StackListLib)
add_subdirectory(StackListTests)
