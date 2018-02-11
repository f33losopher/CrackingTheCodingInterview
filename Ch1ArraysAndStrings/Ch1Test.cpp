/*
 * Ch1Test.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: Felix
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Ch1ArraysAndStrings

#include "Ch1.h"
#include <boost/test/unit_test.hpp>
using namespace std;
using namespace boost;


BOOST_AUTO_TEST_CASE(CH1_prob1)
{
    bool expected_value = true;
    CH1 ch1 = CH1();

    expected_value = true;
    string input = "abcdefg";
    BOOST_CHECK(expected_value == ch1.prob1(input));

    expected_value = false;
    input = "abcdefga";
    BOOST_CHECK(expected_value == ch1.prob1(input));

    expected_value = false;
    input = "aa";
    BOOST_CHECK(expected_value == ch1.prob1(input));

    expected_value = true;
    input = "a";
    BOOST_CHECK(expected_value == ch1.prob1(input));

    expected_value = true;
    input = "a123j.;lsf";
    BOOST_CHECK(expected_value == ch1.prob1(input));

    expected_value = false;
    input = "a123j.;lsf;";
    BOOST_CHECK(expected_value == ch1.prob1(input));
}

BOOST_AUTO_TEST_CASE(CH1_prob1_modified)
{
    bool expected_value = true;
    CH1 ch1 = CH1();

    expected_value = true;
    string input = "abcdefg";
    BOOST_CHECK(expected_value == ch1.prob1_modified(input));

    expected_value = false;
    input = "abcdefga";
    BOOST_CHECK(expected_value == ch1.prob1_modified(input));

    expected_value = false;
    input = "aa";
    BOOST_CHECK(expected_value == ch1.prob1_modified(input));

    expected_value = true;
    input = "a";
    BOOST_CHECK(expected_value == ch1.prob1_modified(input));

    expected_value = true;
    input = "a123j.;lsf";
    BOOST_CHECK(expected_value == ch1.prob1_modified(input));

    expected_value = false;
    input = "a123j.;lsf;";
    BOOST_CHECK(expected_value == ch1.prob1_modified(input));

    expected_value = false;
    input = "aA";
    BOOST_CHECK(expected_value == ch1.prob1_modified(input));
}
