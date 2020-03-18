#include <iostream>
using namespace std;

/*
String Rotation: Assume you have a method i5Substring which checks ifone word is a substring
of another. Given two strings, 51 and 52, write code to check if 52 is a rotation of 51 using only one
call to isSubstring (e.g., Uwaterbottleuis a rotation ofuerbottlewatU). 


First Approach: Sorting

We can sort the two strings and check if they are the same word.
Time Complexity: O(NlogN)
Space Complexity: O(1)

Second Approach: Data Structure

We can use a hashmap to keep track of what chartacters occur in the words and at what frequency. 
We return true if the chracters and frequencies match up.
Time Complexity: O(N)
Space Complexity: O(N)

Third Approach: IsSubstring

If we imagine that 52 is a rotation of 51, then we can ask what the rotation point is. For example, if you
rotate waterbottle after wat, you get erbottlewat. In a rotation, we cut 51 into two parts, x and y,
and rearrange them to get 52.
51 = xy = waterbottle
x = wat
206 Cracking the Coding Interview, 6th Edition 
Solutions to Chapter 1 I Arrays and Strings
y = erbottle
52 = yx = erbottlewat
So, we need to check if there's a way to split 51 into x and y such that xy = 51 and yx = 52. Regardless of
where the division between x and y is, we can see that yx will always bea substring ofxyxy. That is, 52 will
always be a substring of 5151.
And this is precisely how we solve the problem: simply do i5Sub5tring( 5151, 52). 
*/

bool isSubstring(string bigger, string smaller) {

  if(bigger.length() < smaller.length()) {
    throw "Invalid inputs! First param must be the bigger string";
  }

  int smaller_ptr = 0;

  for(int i = 0; i < bigger.length(); ++i) {
    if(bigger[i] == smaller[smaller_ptr]) {
      
      if(smaller_ptr == smaller.length()-1) {
        return true;
      }
      smaller_ptr++;
    } else {
      smaller_ptr=0;
    }
  }
  return false;
}

bool isRotation(string s1, string s2) {
  if(s1.length() == s2.length()) {
    string s1s1 = s1+s1;
    return isSubstring(s1s1, s2);
  }
  return false;
}

int main() {

  cout << isSubstring("big bus", "bus") << endl;
  cout << isSubstring("big bus", "big") << endl;
  cout << isSubstring("big bus", "g b") << endl;
  cout << isSubstring("big bus", "lord") << endl;
  cout << isSubstring("big bus", "buss") << endl;

  return 0;
}