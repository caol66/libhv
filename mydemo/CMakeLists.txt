
include_directories(. .. ../base ../ssl ../event ../util)

#mydemo
list(APPEND MYLIBS "ws2_32" "user32")
add_executable(mydemo mydemo.cpp)
target_link_libraries(mydemo ${MYLIBS})


list(APPEND MYDEMO mydemo)


#add_custom_target(examples DEPENDS ${EXAMPLES})
