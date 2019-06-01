file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${ViewTableTest} ${srcs} ${hdrs})
target_link_libraries(${ViewTableTest} ${ViewTableLib} ${PolandLib} gtest)
