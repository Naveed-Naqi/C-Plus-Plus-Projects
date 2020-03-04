#include <iostream>
#include <regex>
#include <unordered_map>
using namespace std;

// Given a string, return whether or not it is a permutation of a palindrome.

/*
Thought Process:

The quickest and dirtiest solution is to generate all possible permutations of a
string and loop through them all to find one that is a palindrome. This is
highly inefficient, we have a O(2^n) run time.

Instead we can levarage the definitions of what we are looking for and use them
to create a more optimal solution. In order for something to be a palindrome, it
must have the ability to be mirrored on either side. That means that there must
be an even number of all letters, except for a MAX of one. Only one letter is
allowed to occur an odd number of times.

So lets parse through the input string and count the occurences of each number
*/

bool isOdd(const int &num) { return num % 2 == 1; }

bool palindromePermutation(string s) {
  std::unordered_map<char, int> map;

  for (char c : s) {
    map[c]++;
  }

  int num_of_odd_letters = 0;

  for (auto itr = map.begin(); itr != map.end(); ++itr) {
    std::size_t occurences = itr->second;

    // Talk about the benefits of splitting this up to its own separate
    // function.
    if (isOdd(occurences)) {
      num_of_odd_letters++;

      if (num_of_odd_letters > 1) {
        return false;
      }
    }
  }

  return true;
}

/*
The above solution can be done in one pass by keeping track of the number of odd
letters as we populate the map initially and then checking that number at the
end. It is implemented below. The one pass is not neccesarily more owptimal
because even though we don't have to parse through the entier hash mpa at the
end, we sitll have to do an additional operation for each
*/

bool palindromePermuationOnePass(string s) {
  std::unordered_map<char, int> map;
  int num_of_odd_letters = 0;

  for (char c : s) {
    map[c]++;

    if (isOdd(map[c])) {
      num_of_odd_letters++;
    } else {
      num_of_odd_letters--;
    }
  }

  return num_of_odd_letters <= 1;
}

/*
The above two solutions are assuming that the input string would only be one
word and would have no spaces or other punctuation. It is a good calrifying
question to ask in the beginning of the interview. Ask about punctuation/spaces
and other possible contents of the string when dealing with these questions.
Make sure you know what to return in each case.

If other punctuation and/or spaces can be expected in the string,
we can write a quick helper function to clean up the string and only return what
we want. We can use Regex. If you don't remember exactly how to do it during the
interview, this is soe,thing you can just hand wave away. It's not integral to
the core algorithm, but it shows that you are thinking about all possibilities.
*/

string toLowerCase(string s) {

  for (char &c : s) {
    c = tolower(c);
  }

  return s;
}

std::string clean(std::string s) {
  regex not_letters("[^A-Za-z]");
  string result = regex_replace(s, not_letters, "");
  return toLowerCase(result);
}

/*
Build up a habit of always asking about edge case inputs when given a question
that requires an input. It shows that you are thinking outsdie of the box and
are willing to addapt and change our solution if given non-perfect conditions.
*/

/*
The most optimal solution will use a bitset of length 26
and only keep track of whether the count of each letter is even or odd by
toggling the element at that index. This solution saves a lot of space because a
bitset of length 26 only takes up 26 bits, whereas our previous solutions use at
least one integer to keep track of the count and the integer alone is 4 bytes =
32 bits.
*/

bool palindromePermutationBitSet(string s) {
  bitset<26> map;

  for (char &c : s) {
    size_t index = (int)c - 97;
    map.flip(index);
  }

  size_t counter = 0;

  for (size_t i = 0; i < map.size(); ++i) {
    if (map.test(i)) {
      counter++;
      if (counter > 1) {
        return false;
      }
    }
  }

  /*
  It still uses O(N) runtime and there is a more elegant way to check if there
  is more than a single 1 in the bitvector after you've gone through it, however
  that requires an intimate knowledge of binary numbers and operators. We might
  revisit this implementation after we finish Chapter 5.
  */

  return true;
}

int main() {

  clean("1231sjnalma;aw,dAADs  4165wtgdbA");

  cout << palindromePermuationOnePass("racecar");
  cout << palindromePermuationOnePass("rraacce");
  cout << palindromePermuationOnePass("spoon");
  cout << palindromePermuationOnePass("largeboi");
  cout << palindromePermuationOnePass("rraacc");
  cout << palindromePermuationOnePass("rraaccggvvve");
  return 0;
}