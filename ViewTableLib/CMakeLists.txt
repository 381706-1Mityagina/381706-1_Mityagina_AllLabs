file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${ViewTableLib} STATIC ${srcs} ${hdrs}) 
