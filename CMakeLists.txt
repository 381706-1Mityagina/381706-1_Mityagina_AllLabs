cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-1_Mityagina_AllLabs) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set (Vector Vector)
set(VectorLib VectorLib) #Переменная с именем библиотеки
set (VectorTest VectorTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ VectorLib ${CMAKE_CURRENT_SOURCE_DIR}/gtest)

add_subdirectory(Vector)
add_subdirectory(VectorLib)
add_subdirectory(VectorTest)
add_subdirectory(gtest)
