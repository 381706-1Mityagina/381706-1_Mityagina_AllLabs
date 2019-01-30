file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${MonomialTest} ${srcs} ${hdrs})
target_link_libraries(${MonomialTest} ${MonomialLib} gtest)
