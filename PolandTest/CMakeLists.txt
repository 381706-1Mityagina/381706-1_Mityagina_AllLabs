file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${PolandTest} ${srcs} ${hdrs})
target_link_libraries(${PolandTest} ${PolandLib} gtest)
