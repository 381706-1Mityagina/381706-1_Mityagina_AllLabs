cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME AllLabs) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set (Monomial Monomial)
set(MonomialLib MonomialLib)
set (MonomialTest MonomialTest)

set (Polinomial Polinomial)
set(PolinomialLib PolinomialLib)
set (PolinomialTest PolinomialTest)

set(Exception Exception)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()


#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Exception)
add_subdirectory(Exception)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MonomialLib)
add_subdirectory(Monomial)
add_subdirectory(MonomialLib)
add_subdirectory(MonomialTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolinomialLib)
add_subdirectory(Polinomial)
add_subdirectory(PolinomialLib)
add_subdirectory(PolinomialTest)
