cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-1_Mityagina_AllLabs) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(Vector Vector) #Переменная с именем библиотеки
set(VectorLib VectorLib)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories (VectorLib)
add_subdirectory (Vector)

add_subdirectory (VectorLib)

#add_library(${VectorLib} STATIC ${srcs} ${hdrs}) #Создаем статическую библиотеку с именем из переменной ${MyLib1}, объявленной в родительском CMake файле (локальные переменные переносятся в наследников), в неё добавляются файлы из переменных ${srcs} и ${hdrs}

#add_subdirectory(lib1) #Собираем проект в поддиректории lib1
#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}