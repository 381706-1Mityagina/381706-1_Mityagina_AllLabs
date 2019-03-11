cmake_minimum_required(VERSION 2.8) 

set(PROJECT_NAME AllLabs) 
project(${PROJECT_NAME}) 

set (ArrayList ArrayList)
set(ArrayListLib ArrayListLib) 
set (ArrayListTests ArrayListTests)

set(Exception Exception)

set(QueueLib QueueLib)

set(StackLib StackLib)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)  
if(NOT CMAKE_BUILD_TYPE) 
  set(CMAKE_BUILD_TYPE Release) 
endif()

file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 


#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ArrayListLib)
add_subdirectory(ArrayList)
add_subdirectory(ArrayListLib)
add_subdirectory(ArrayListTests)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Exception)
add_subdirectory(Exception)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
add_subdirectory(QueueLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
add_subdirectory(StackLib)
