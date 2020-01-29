#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool checkPermutation(string some_string, string other_string) {

  unordered_map<char, int> map;

  if(some_string.size() != other_string.size()) { return false; }

  for(int i = 0; i < some_string.size(); ++i) {
    map[some_string[i]]++;
    map[other_string[i]]++;
  }

  for(auto itr = map.begin(); itr != map.end(); ++itr) {
    if(itr->second % 2 == 1) {
      return false;
    }
  }

  cout << "yes \n";
  return true;
}

bool checkPermutationNoDS(string some_string, string other_string) {

  if(some_string.size() != other_string.size()) { return false; }

  std::sort(some_string.begin(), some_string.end());
  std::sort(other_string.begin(), other_string.end());

  for(int i = 0; i < some_string.size(); ++i) {
    if(some_string[i] != other_string[i]) { 
      return false;
    }
  }

  return true;
}

int main() {

  checkPermutationNoDS("racecar", "rrccaae"); //TRUE
  checkPermutationNoDS("please", "leeaps"); //TRUE
  checkPermutationNoDS("racecar", "memesynopsis");
  checkPermutationNoDS("racecar", "rraacc");
  checkPermutationNoDS("racecar", "carecar"); //TRUE
  checkPermutationNoDS("racecar", "racerac"); //TRUE

  return 0;
}