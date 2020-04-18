#include <iostream>
#include <stack>
using namespace std;

/*
Min Stack: Implement a stack data structure that does push(), pop() and min() in constant time.

First Approach: 2 Stacks

I used on stack to keep track of the values and the second stack to keep track of the min_values.
I add all values that are less than or equal to the current min to the min stack. This does open the door for a small optimization.

Instead of just adding values to the min stack. I could add special min nodes that contain a value and the number of times that values exists.
For example, if I need to add 2000 5s to my queue, and 5 is the min. Instead of adding 2000 5s. I could add one 5, that keeps track of the number of occurences that it has.
This optimization is definitley worth discussing with your interviewer in the event that you need to optimize for large data sets that contain duplicates.
*/

class MinStack {
public:
  MinStack(){};

  void push(const int& val) {
    values.push(val);

    if (min_values.empty() || val <= min_values.top()) {
      min_values.push(val);
    }
  }

  void pop() {

    if (values.empty()) {
      throw "Min Stack does not contain any values";
    }

    if (values.top() == min_values.top()) {
      min_values.pop();
    }

    values.pop();
  }

  int peek() {

    if (values.empty()) {
      throw "Min Stack does not contain any values";
    }

    return values.top();
  }

  int min() {

    if (min_values.empty()) {
      throw "Min Stack does not contain any values";
    }

    return min_values.top();
  }

private:
  stack<int> values;
  stack<int> min_values;
};

int main() {

  try {
    MinStack test;

    const int size = 7;
    int list[size] = {6, 12, 3, 4, 5, 6, 2};

    for (int i = 0; i < size; ++i) {
      test.push(list[i]);
    }

    test.pop();

    cout << test.min();

  } catch (const char* e) {
    cout << e;
  }

  return 0;
}