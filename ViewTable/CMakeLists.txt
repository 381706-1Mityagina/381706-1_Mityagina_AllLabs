file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 
add_executable(${ViewTable} ${srcs} ${hdrs}) 

target_link_libraries(${ViewTable} ${ViewTableLib})
