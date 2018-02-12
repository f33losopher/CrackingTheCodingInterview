/*
 * Ch1.h
 *
 *  Created on: Feb 6, 2018
 *      Author: Felix
 */

#ifndef CH1_H_
#define CH1_H_

#include <map>
#include<string>

class CH1 {
public:
	CH1();

	// Implement an algorithm to determine if a string has all unique characters. What if you
	// can not use additional data structures?
	bool prob1(const std::string& s);
	bool prob1_modified(const std::string& s);

	// Write code to reverse a C-style String. (C-String means that "abcd" is represented as
	// five characters, including null character.)
	char* prob2(const char* str, int length);
	const char* prob2(const char* str);

	// Design an algorithm and write code to remove the duplicate characters in a string
	// without using any additional buffer. NOTE: One or two additional variables are fine.
	// An extra copy of the array is not
	// FOLLOW UP
	// Write the test cases for this method.
	void prob3(std::string& str);
	void prob3(char* str);

	// Write a method to decide if two strings are anagrams or not
	bool prob4_sort(std::string& str1, std::string& str2);
	bool prob4_maps(std::string& str1, std::string& str2);
	bool prob4_hash(std::string& str1, std::string& str2);

	void printCstring(char* str);
	void printMap(std::map<char, int>& m);
private:
	void populateMap(std::map<char, int>& m, std::string str);
	const bool mapsEqual(const std::map<char, int>& m1, const std::map<char, int>& m2) const;
	unsigned long genHash(const std::string& m);

};




#endif /* CH1_H_ */
