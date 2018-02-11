/*
 * Ch1.h
 *
 *  Created on: Feb 6, 2018
 *      Author: Felix
 */

#ifndef CH1_H_
#define CH1_H_

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
	char* prob2(char* str, int length);

private:

};




#endif /* CH1_H_ */
