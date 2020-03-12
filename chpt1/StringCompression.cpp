#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
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

Should we convert everything to lowrer/upper case. Is uppercase disticnt from lowercase in this problemd. 
For simplicity's sake let's assume it is, but understand what you would do if it was not distinct.

First Approach: Sorting
The first think I think of is to sort the string and parse through it once while
creating a new output string.

Time: O(NlogN)
Space: O(1) if not counting the space of the newly created string.

*/

std::string compressionSorting (string input) {

  string result = "";
  string original_input = input;

  std::sort(input.begin(), input.end()); //O(NlogN) time, Quicksort so it takes no additional space

  cout << input << endl;

  char curr_letter = input[0];
  int curr_count = 1;

  for(int i = 1; i < input.length(); ++i) {

    if(curr_letter != input[i]) {
      result += curr_letter + to_string(curr_count);
      curr_letter = input[i];
      curr_count = 1;
    } else {
      ++curr_count;
    }
  }

  result += curr_letter + to_string(curr_count);
  return result.length() < original_input.length() ? result : original_input;

}

/*
Second Approach: Hashmap

We can parse through the string once and use a hashmap to record the characters that are in the stirng along with the number of occurences.
This will increase our space complexity to O(N), but we will have a time complexity of O(N) as well instead of O(NlogN).
This is a good thing to discuss with your interviewer because it shows that you can assess the tradeoffs between different approaches.
*/

string compressionHashMap(string input) {
  unordered_map<char, int> map;
  string result = "";

  for(char letter : input) {
    map[letter]++;
  }

  for(auto itr = map.begin(); itr != map.end(); ++itr) {
    result += itr->first + to_string(itr->second);
  }

  return result.length() < input.length() ? result : input;
}

int main() {

  string result = compressionHashMap("aabbcc");
  cout << result;

  return 0; 
}