file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${ListTests} ${srcs} ${hdrs})
target_link_libraries(${ListTests} ${ListLib} gtest)
