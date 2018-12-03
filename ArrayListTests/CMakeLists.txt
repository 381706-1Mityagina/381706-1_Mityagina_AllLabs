file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${ArrayListTests} ${srcs} ${hdrs})
target_link_libraries(${ArrayListTests} ${ArrayListLib} gtest)
