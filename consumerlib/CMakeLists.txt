project(ConsumerLib)

set (
    CONSUMER_LIB_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Foo.cxx
)

set (
    CONSUMER_LIB_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Foo.h
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(
    ConsumerLib SHARED 
    ${CONSUMER_LIB_SRC} 
    ${CONSUMER_LIB_HEADERS}
)

