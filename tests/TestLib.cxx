//  Copyright 2018 Uncle Ben

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <boost/test/unit_test.hpp>
#include "Foo.h"

BOOST_AUTO_TEST_SUITE(Test_Library)


BOOST_AUTO_TEST_CASE(TestHello) {
      BOOST_CHECK_EQUAL("hello world", Foo::bar("hello"));
}



BOOST_AUTO_TEST_SUITE_END()
