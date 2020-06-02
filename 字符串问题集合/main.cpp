#pragma once

#include "CommonHeader.h"
#include "reverseString.h"

std::vector<int> first;                                // empty vector of ints
std::vector<int> second (4,100);                       // four ints with value 100
std::vector<int> third (second.begin(),second.end());  // iterating through second
std::vector<int> fourth (third);                       // a copy of third

// the iterator constructor can also be used to construct from arrays:
int myints[] = {16,2,77,29};
std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );


void testReverseString()
{
	char s1[] = {'h', 'e', 'l', 'l', 'o'};
	char s2[] = {'H', 'a', 'n', 'n', 'a', 'h'};
	vector<char> s1_v(s1, s1 + sizeof(s1) / sizeof(char));
	vector<char> s2_v(s2, s2 + sizeof(s2) / sizeof(char));
	Solution::reverseString(s1_v);
	Solution::reverseString(s2_v);
}

int main()
{
	testReverseString();
	return 0;
}