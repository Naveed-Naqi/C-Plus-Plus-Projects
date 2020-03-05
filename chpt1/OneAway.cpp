#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
One Away: There are three types of edits that can be performed on strings:
insert a character, remove a character, or replace a character. Given two
strings, write a function to check if they are one edit (or zero edits) away.
*/

/*
Thought Process:

First things first, edge cases:
Will we have to deal with any extraneous characters like punctaton or
whitespace? If we have two strings like this: 'able' and ' able '. They are
technically two characters away, but should our solution return them as two
characters away?

It is a good question to ask, just to make sure. For our implementation, let's
just assume that we don't need to do any type of cleanup with the strigns and
they will just be single words when they are input into our function.

First Approach: Sorting

Obviously if the length of the two strings differs by greater than 1, we return
false right away. Otherwise, we can sort the two strings and parse through them
at the same time and count the differences. If the number of differences exceeds
one, then we return false. This sounds feasibly but a little complicate to
implement because we are going to need to account for a bunch of different
scenarios.

Time: O(NlogN)
Space: O(1)

Second Approach: 2 Hash Tables
Put the two strings into a hashmap to keep track of the characters and number of
occurences, then compare the two hashmaps. This sounds like it will work and it
seems less complicated to code than our initial approach. If feels like we can
still optimize it though.

Time: O(N)
Space: O(N)

Third Approach: 1 Hash Table
After thinking a little more about the problem, using two hashtables seemes
unnecesary. We can attain all the necessary information by just looking at
whether the occurence of each character is even or odd. If the strings must
differ by at most one character, that means that if we hold the sums of each
character across both strings in a hashtable, there MUST BE a single
character that has an odd nunber of occurences if the difference of string
lengths is 1. Otherwise, if the difference in string lengths is 0, then there
MUST BE 2 letters that have one odd occurence. Let's implement this solution.

Time: O(N)
Space: O(N)
*/

void populateMap(unordered_map<char, int> &map, string arr[], int size) {

  for (int i = 0; i < size; ++i) {
    for (char &c : arr[i]) {
      map[c]++;
    }
  }
}

bool oneAwayOneHashTable(string a, string b) {
  int size_a = a.length();
  int size_b = b.length();
  int diff = abs(size_a - size_b);

  if (diff > 1) {
    return false;
  }

  unordered_map<char, int> map;

  string arr[2] = {a, b};

  populateMap(map, arr, 2);

  // Seperating this populateMap process into its own separate function is a
  // nice way of writing code that is cleaner. We could
  // generalize this functoin more. You can discuss the stylistic
  // tradeoffs with the interviewer.

  int num_of_odd_occurences = 0;

  for (auto itr : map) {
    if (itr.second % 2 == 1) {
      num_of_odd_occurences++;
    }
  }

  if (diff == 0) {
    return (num_of_odd_occurences == 2 || num_of_odd_occurences == 0);
  } else {
    return num_of_odd_occurences == 1;
  }
}

/*

Fourth Approach: Bitset
We can further optimize the amount of space this function takes up by using a
bitset instead of hash table. We can do this because we don't actually care
about the numbere of occurences of each charatcer, we just care about whether
they are even or odd. This is a nice optimization to bring up in an interview.
However, it doesn't change the time or space complxity but it is strictly
better in terms of number of bits that the solution will take up.

Time: O(N)
Space: O(N)
*/

bool oneAwayOneBitVector(string a, string b) {
  int size_a = a.length();
  int size_b = b.length();
  int diff = abs(size_a - size_b);

  if (diff > 1) {
    return false;
  }

  bitset<26> map;

  string arr[2] = {a, b};

  for (char &c : a) {
    size_t pos = (int)c - 97;
    map.flip(pos);
  }

  for (char &c : b) {
    size_t pos = (int)c - 97;
    map.flip(pos);
  }

  int num_of_odd_occurences = 0;

  for (int i = 0; i < map.size(); ++i) {
    if (map.test(i)) {
      num_of_odd_occurences++;
    }
  }

  if (diff == 0) {
    return (num_of_odd_occurences == 2 || num_of_odd_occurences == 0);
  } else {
    return num_of_odd_occurences == 1;
  }
}

/*
Fifth Apprach: No external DS
Provided by the book

Time: O(N)
Space: O(1)
*/

bool oneEditReplace(string a, string b) {

  bool found_diff = false;

  for (int i = 0; i < a.length(); ++i) {
    if (a[i] != b[i]) {
      if (found_diff) {
        return false;
      }
      found_diff = true;
    }
  }

  return true;
}

bool oneEditInsert(string smaller, string larger) {

  int index_smaller = 0, index_larger = 0;

  while (index_smaller < smaller.length() && index_larger < larger.length()) {
    if (smaller[index_smaller] != larger[index_larger]) {
      if (index_smaller != index_larger) {
        return false;
      }
      index_larger++;
    } else {
      index_smaller++;
      index_larger++;
    }
  }

  return true;
}

bool oneAwayNoDS(string a, string b) {
  int size_a = a.length();
  int size_b = b.length();
  int diff = abs(size_a - size_b);

  if (diff > 1) {
    return false;
  }

  if (diff == 0) {
    return oneEditReplace(a, b);
  } else if (size_a + 1 == size_b) {
    return oneEditInsert(a, b);
  } else {
    return oneEditInsert(b, a);
  }
}

/*
The logic of oneEditInsert and oneEditReplace are very similar. One thing to
discuss with an interviewer is the tradeoff between whether or not you should
merge them into one function or keep them separate. You can argue that it is
more readable if kept separate, but merging them into one funcion is better from
a code duplication perspective.

This last implemntation, is very similar to the
initial approach I had with regards to sorting the strings and parsing through
them. I gave up on that appraoch a little bit too quickly. If I had thought
about it a little bit moe I would have been able to coem to the same conclusion
as the book. Also, I overcomplicated it by not truly internalizign and
understanding the problem. There was no need to sort the strings, it foolishly
mad my program slower for no reason.

LESSONS:
Spend a little longer pondering the problem and potential solutions before
jumping ship to somethign else.

When evaluating a solution, think about whether you really need to do every
single step of the algorithm andmake sure that every step is neccesary or
providing value.

A good way to optimize is to try and solve the problem in constant space.
However, there is usually some tradeoff when optimizing for space and that is a
good thing to discuss with your interviewer before even attempting a solution
like that. However, inn this case, there is no real tradeoff, doing it in
constant space is strictly better

Bitsets are cool and useful for decreasing the number of bits a solution
takes up, although they don't have any effect on the time or space compelxity of
a solution.

*/

int main() {

  cout << oneAwayNoDS("abcwdasda", "abcwdasda"); // 1
  cout << oneAwayNoDS("abcwdasda", "abcwdsda");  // 1
  cout << oneAwayNoDS("abcwdasda", "abcwqasda"); // 1
  cout << oneAwayNoDS("abcwdasda", "abcwdwsda"); // 1
  cout << oneAwayNoDS("abcwdasda", "abdasda");   // 0
  cout << oneAwayNoDS("absda", "abcwdasda");     // 0

  return 0;
}