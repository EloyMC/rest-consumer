project(ConsumerBin)

set (CURL_LIBRARY "-lcurl")

find_package(CURL REQUIRED)

set (
    CONSUMER_BIN_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/src/RestConsumer.cxx
)

set (
    CONSUMER_BIN_INCLUDE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Main.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/RestConsumer.h
)

include_directories(
    ${CMAKE_SOURCE_DIR}/consumerlib/include
    ${CURL_INCLUDE_DIR}
)

add_executable(
    ConsumerBin 
    ${CONSUMER_BIN_SRC} 
    ${CONSUMER_BIN_INCLUDE}
)

target_link_libraries(
    ConsumerBin 
    ConsumerLib 
    ${CURL_LIBRARIES}
)