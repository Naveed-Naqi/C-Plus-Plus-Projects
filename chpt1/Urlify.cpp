#include <iostream>

using namespace std;


//O(n) space and time
string urlify(string s) {
  string result = "";

  for(int i = 0; i < s.length(); ++i) {
    if(s[i] == ' ') {
      result+= "%20";
    } else {
      result+=s[i];
    }
  }
  cout << result << "\n";
  return result;
}

int main() {

  urlify("My name is john");
;
  return 0;
}