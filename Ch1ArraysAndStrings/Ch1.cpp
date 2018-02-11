/*
 * Ch1.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: Felix
 */

#include "Ch1.h"
#include<iostream>

using namespace std;

CH1::CH1() { }

// Questions I would ask
// - Does lower and upper case count as different letters? - Assume they are the same
// - What is the valid character set? - basic 128 set of ascii chars
bool CH1::prob1(const string& str) {
	bool rtn = true;

	// using data structure.
	int seen[128] = {0};
	for (char c: str) {
		if (seen[c] == 1) {
			rtn = false;
			break;
		} else {
			seen[c] = 1;
		}
	}

	return rtn;
}
bool CH1::prob1_modified(const string& str) {
	bool rtn = true;
	unsigned long seen[2] = {0};
	for (char c: str) {
		// Make c uppercase if necessary
		if (c >= 'a' && c <= 'z') {
			c -= ('a' - 'A');
		}

		int idx = (int) c / 64;
		int shift = c % 64;
		unsigned long mask = 1UL << shift;

		if ((seen[idx] & mask) > 0) {
			rtn = false;
			break;
		} else {
			seen[idx] |= mask;
		}
	}

	return rtn;
}



