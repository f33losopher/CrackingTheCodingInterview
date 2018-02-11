/*
 * Ch1Test.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: Felix
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Ch1ArraysAndStrings

#include "Ch1.h"
#include <iostream>
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

BOOST_AUTO_TEST_CASE(CH1_prob2) {
	CH1 ch1 = CH1();
	char* answer;

	char s1[] = "abcd";
	answer = ch1.prob2(s1, sizeof(s1)/sizeof(s1[0]));
	BOOST_CHECK(strcmp(answer, "dcba") == 0);

	char s2[] = "123abc456789";
	answer = ch1.prob2(s2, sizeof(s2)/sizeof(s2[0]));
	BOOST_CHECK(strcmp(answer, "987654cba321") == 0);

	char s3[] = "";
	answer = ch1.prob2(s3, 1);
	BOOST_CHECK(strcmp(answer, "") == 0);

	char s4[] = "a";
	answer = ch1.prob2(s4, sizeof(s4)/sizeof(s4[0]));
	BOOST_CHECK(strcmp(answer, "a") == 0);
}

BOOST_AUTO_TEST_CASE(CH1_prob2_modified) {
	CH1 ch1 = CH1();
	const char* answer;

	char s1[] = "abcd";
	answer = ch1.prob2(s1);
	BOOST_CHECK(strcmp(answer, "dcba") == 0);

	char s2[] = "123abc456789";
	answer = ch1.prob2(s2);
	BOOST_CHECK(strcmp(answer, "987654cba321") == 0);

	char s3[] = "";
	answer = ch1.prob2(s3);
	BOOST_CHECK(strcmp(answer, "") == 0);

	char s4[] = "a";
	answer = ch1.prob2(s4);
	BOOST_CHECK(strcmp(answer, "a") == 0);
}

BOOST_AUTO_TEST_CASE(CH1_prob3) {
	string str = "abcdefg";
	CH1 ch1 = CH1();

	ch1.prob3(str);
	BOOST_CHECK(str == "abcdefg");

	str = "abcdefga";
	ch1.prob3(str);
	BOOST_CHECK(str == "abcdefg");

	str = "aaabbbcccd";
	ch1.prob3(str);
	BOOST_CHECK(str == "abcd");

	str = "abababababababa";
	ch1.prob3(str);
	BOOST_CHECK(str == "ab");
}

BOOST_AUTO_TEST_CASE(CH1_prob3_modified) {
	char str[] = "abcdefg";
	CH1 ch1 = CH1();

	ch1.prob3(str);
	BOOST_CHECK(strcmp(str, "abcdefg") == 0);

	char str2[] = "abcdefga";
	ch1.prob3(str2);
	BOOST_CHECK(strcmp(str2, "abcdefg") == 0);

	char str3[] = "aaabbbcccd";
	ch1.prob3(str3);
	BOOST_CHECK(strcmp(str3, "abcd") == 0);

	char str4[] = "abababababababa";
	ch1.prob3(str4);
	BOOST_CHECK(strcmp(str4, "ab") == 0);
}
