PROJECT(Consumer_tests)

SET(
    CONSUMER_TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/TestLib.cxx
)
include_directories(${CMAKE_SOURCE_DIR}/consumerlib/include )

FIND_PACKAGE(
    Boost 1.53 COMPONENTS 
    unit_test_framework 
    REQUIRED
)

ADD_EXECUTABLE(Tests ${CONSUMER_TEST_SOURCES})

TARGET_LINK_LIBRARIES(
    Tests
    ConsumerLib
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

ADD_TEST(ConsumerTest Tests)