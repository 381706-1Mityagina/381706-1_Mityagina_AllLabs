cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME AllLabs) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(Exception Exception)

##set(Vector Vector)
##set(VectorLib VectorLib)
##set(VectorTest VectorTest)

##set(Matrix Matrix)
##set(MatrixLib MatrixLib)
##set(MatrixTest MatrixTest)

set(Stack Stack)
set(StackLib StackLib)
set(StackTest StackTest)

##set(Queue Queue)
##set(QueueLib QueueLib)
##set(QueueTest QueueTest)

##set(List List)
##set(ListLib ListLib)
##set(ListTests ListTests)

##set(MStack MStack)
##set(MStackLib MStackLib)
##set(mStackTest mStackTest)

##set(ArrayList ArrayList)
##set(ArrayListLib ArrayListLib)
##set(ArrayListTests ArrayListTests)

##set(Polinomial Polinomial)
##set(PolinomiallLib PolinomiallLib)
##set(PolinomialTest PolinomialTest)

##set(MonomialLib MonomialLib)
##set(MonomialTest MonomialTest)

##set(StackList StackList)
##set(StackListLib StackListLib)
##set(StackListTest StackListTest)

##set(Poland Poland)
##set(PolandLib PolandLib)
##set(PolandTest PolandTest)


set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Exception)
add_subdirectory(Exception)

##include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib)
##add_subdirectory(Vector)
##add_subdirectory(VectorLib)
##add_subdirectory(VectorTest)

##include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MatrixLib)
##add_subdirectory(Matrix)
##add_subdirectory(MatrixLib)
##add_subdirectory(MatrixTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
add_subdirectory(Stack)
add_subdirectory(StackLib)
add_subdirectory(StackTest)

##include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
##add_subdirectory(Queue)
##add_subdirectory(QueueLib)
##add_subdirectory(QueueTest)

##include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ArrListLib)
##add_subdirectory(ArrayList)
##add_subdirectory(ArrayListLib)
##add_subdirectory(ArrayListTests)

##include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
##add_subdirectory(List)
##add_subdirectory(ListLib)
##add_subdirectory(ListTests)

##include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MultiStackLib)
##add_subdirectory(MStack)
##add_subdirectory(MStackLib)
##add_subdirectory(mStackTest)

##include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolinomialLib)
##add_subdirectory(Polinomial)
##add_subdirectory(PolinomialLib)
##add_subdirectory(PolinomialTest)

##include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MonomialLib)
##add_subdirectory(MonomialLib)
##add_subdirectory(MonomialTest)

##include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackListLib)
##add_subdirectory(StackList)
##add_subdirectory(StackListLib)
##add_subdirectory(StackListTest)

##include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolishLib)
##add_subdirectory(Poland)
##add_subdirectory(PolandLib)
##add_subdirectory(PolandTest)
