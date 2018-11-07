file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${Queue} ${srcs} ${hdrs})
target_link_libraries(${Queue} ${QueueLib})