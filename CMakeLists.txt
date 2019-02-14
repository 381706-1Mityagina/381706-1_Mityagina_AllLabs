cmake_minimum_required(VERSION 2.8) 

set(PROJECT_NAME 381706-1_Mityagina_AllLabs) 
project(${PROJECT_NAME}) 

set(StackLib StackLib)
 
set(QueueLib QueueLib)

set(Exception Exception) 

set(PolandLib PolandLib)
set(Poland Poland)
set(PolandTest PolandTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)  
if(NOT CMAKE_BUILD_TYPE) 
  set(CMAKE_BUILD_TYPE Release) 
endif()

file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 


#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Exception)
add_subdirectory(Exception)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
add_subdirectory(QueueLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
add_subdirectory(StackLib StackLib) 

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolandLib)
add_subdirectory(PolandLib PolandLib) 
add_subdirectory(Poland Poland) 
add_subdirectory(PolandTest PolandTest) 

