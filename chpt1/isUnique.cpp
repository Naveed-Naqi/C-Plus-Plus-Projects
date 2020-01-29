//Implement an algorithm to determine if a string has all unique characters

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


//O(NlogN) time because of the sorting
//O(1) space
bool isUniqueNoDS(string s) {
  std::sort(s.begin(), s.end());

  for(int i = 0; i < s.size()-1; ++i) {
    if(s[i] == s[i+1]) {
      return false;
    }
  }
  return true;
}

//O(N) time
//O(N) space
bool isUnique(string s) {

  unordered_map<char, bool> freq_map;

  for(char c: s) {
    if(freq_map[c]) {
      return false;
    } else {
      freq_map[c] = true;
    }
  }
  return true;
}

int main() {

  string test1 = "abjdhbadakdl";
  string test2 = "lkjhgfdsa"; //TRUE
  string test3 = "qwertyuio"; //TRUE
  string test4 = "dablsdka;lndakd";
  string test5 = "ldbhakjslnfap'daod";

  isUniqueNoDS(test1);
  isUniqueNoDS(test2);
  isUniqueNoDS(test3);
  isUniqueNoDS(test4);
  isUniqueNoDS(test5);

  return 0;
}