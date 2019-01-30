file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${PolinomialTest} ${srcs} ${hdrs})
target_link_libraries(${PolinomialTest} ${PolinomialLib} gtest)
