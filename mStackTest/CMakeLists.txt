file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${mStackTest} ${srcs} ${hdrs})
target_link_libraries(${mStackTest} ${MStackLib} gtest)
