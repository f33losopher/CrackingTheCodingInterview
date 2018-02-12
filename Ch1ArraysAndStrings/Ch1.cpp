/*
 * Ch1.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: Felix
 */

#include "Ch1.h"
#include<iostream>

#include <algorithm>
#include <cstring>
#include <map>
#include <string>

using namespace std;

CH1::CH1() {
}

// Questions I would ask
// - Does lower and upper case count as different letters? - Assume they are the same
// - What is the valid character set? - basic 128 set of ascii chars
bool CH1::prob1(const string& str) {
	bool rtn = true;

	// using data structure.
	int seen[128] = { 0 };
	for (char c : str) {
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
	unsigned long seen[2] = { 0 };
	for (char c : str) {
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

// Questions I would ask
// - Can I assume the user will send in the length? Or do I need to determine that?
// - lets do it both ways!!
// - Can I swap it in place, or do I need to make a new copy. Let's say new copy to be clean
char* CH1::prob2(const char* str, int length) {
	char* rtn = new char[length];
	if (length <= 2) {
		memcpy(rtn, str, length);
	} else {
		int beg = 0;
		int end = length - 2;
		while (beg < end) {
			rtn[beg] = str[end];
			rtn[end] = str[beg];
			beg++;
			end--;
		}
		rtn[length - 1] = '\0';
	}
	return rtn;
}

const char* CH1::prob2(const char* str) {
	// Can just figure out the length and call the previous method
//	int length = 1;
//	while (str[length -1] != '\0') {
//		length++;
//	}
//	return prob2(str, length);

	int idx = 0;
	string rtn;
	while (str[idx] != '\0') {
		rtn.insert(0, 1, str[idx]);
		idx++;
	}
	return rtn.c_str();
}


// Questions I would ask
// - What should the input be? String or Char*? Let's just do it for both
// - Since we can't make a copy, will assume that we are modifying the input in place
// - Is the input set just letters, numbers, special characters? Let's just assume 128 character ascii set
void CH1::prob3(std::string& str) {
	if (str.length() <= 1)
		return;

	unsigned long seen[2] = {0};
	unsigned long mask = 0;

	for (unsigned int i=0; i < str.length(); ++i) {
		// 2 cases, if we seen this char, then delete it
		// if we haven't add the bit mask to seen
		int idx = str[i] / 64;
		int shift = str[i] % 64;
		mask = 1UL << shift;

		if ((mask & seen[idx]) == 0) {
			seen[idx] |= mask;
		} else {
			str = str.erase(i, 1);
			i--;
		}
	}
}

void CH1::prob3(char* str) {
	int cur = 0;
	int rep = 0;

	unsigned long seen[2] = {0};
	unsigned long mask = 0;

	while (str[cur] != '\0') {
		int idx = str[cur] / 64;
		int shift = str[cur] % 64;
		mask = 1UL << shift;

		if ((mask & seen[idx]) == 0) {
			seen[idx] |= mask;
			str[rep] = str[cur];
			cur++;
			rep++;
		} else {
			cur++;
		}
	}
	str[rep] = '\0';
}

// Assume inputs are 2 strings
// Here are some options
// 1-Sort the two strings, and then compare them
// 2-Walk through each and keep track of how many letters are in each
// 3-Can I come up with an algorithm to hash a word based on letters where order doesn't matter??
bool CH1::prob4_sort(std::string& str1, std::string& str2) {
	bool rtn = true;
	if (str1.length() != str2.length()) {
		rtn = false;
	} else {
		std::sort(str1.begin(), str1.end());
		std::sort(str2.begin(), str2.end());

		rtn = (str1 == str2);
	}

	return rtn;
}

bool CH1::prob4_maps(std::string& str1, std::string& str2) {
	bool rtn = true;
	if (str1.length() != str2.length()) {
		rtn = false;
	} else {
		map<char, int> map1;
		map<char, int> map2;
		populateMap(map1, str1);
		populateMap(map2, str2);

		rtn = mapsEqual(map1, map2);
	}

	return rtn;
}

bool CH1::prob4_hash(std::string& str1, std::string& str2) {
	bool rtn = true;
	if (str1.length() != str2.length()) {
		rtn = false;
	} else {
		unsigned long hash1 = genHash(str1);
		unsigned long hash2 = genHash(str2);

		cout << "hash1: " << hash1 << " hash2: " << hash2 << endl;
		rtn = (hash1 == hash2);
	}
	return rtn;
}

void CH1::populateMap(std::map<char, int>& m, std::string str) {
	for (unsigned int i=0; i < str.length(); ++i) {
		char c = str[i];
		if (m.find(c) == m.end()) {
			m[c] = 1;
		} else {
			m[c]++;
		}
	}
}

const bool CH1::mapsEqual(const std::map<char, int>& m1, const std::map<char, int>& m2) const {
	bool rtn = true;

	std::map<char, int>::const_iterator m1Itr = m1.begin();
	for (; m1Itr != m1.end(); m1Itr++) {
		char c = m1Itr->first;
		int val = m1Itr->second;

		if ((m2.find(c) == m2.end()) || (m2.find(c)->second != val)) {
			rtn = false;
			break;
		}
	}

	return rtn;
}

void CH1::printMap(map<char, int>& m) {
	map<char, int>::iterator mItr = m.begin();
	for (; mItr != m.end(); mItr++) {
		string c;
		c.insert(0, &mItr->first);

		int val = mItr->second;
		cout << "Key: " << c << " Val: " << val << endl;
	}
}

unsigned long CH1::genHash(const string& m) {
	unsigned long hash = 0;
	for (int i=0; i < m.length(); ++i) {
		unsigned long c = m[i];
		hash += (c * c);
	}
	return hash;
}
