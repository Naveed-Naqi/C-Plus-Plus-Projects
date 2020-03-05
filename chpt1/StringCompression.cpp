#include <iostream>
using namespace std;

/*
String Compression: Implement a method to perform basic string compression using
the counts of repeated characters. For example, the string aabcccccaaa would
become a2blc5a3. If the "compressed" string would not become smaller than the
original string, your method should return the original string. You can assume
the string has only uppercase and lowercase letters (a - z).

Thought Process:

First things first, edge cases:
Clarify with your interviewer that there will/will not be any whitespace in your
input string. For our case, lets assume that thre will not be any whitespace.

First Approach: Sorting
The first think I think of is to sort the string and parse through it once while
creating a new output string.

Time: O(NlogN)
Space: O(1) if not counting the space of the newly created string.

*/

int main() { return 0; }