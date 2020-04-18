#include <iostream>
#include <stack>
using namespace std;

/*
Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks. 

Use one stack to reverse the other stack and perform push bd oeek operationso n that.

*/

class QueueWithStacks {
public:
  void push(const int& val) {
    forward.push(val);
  }

  void pop() {
    while (!forward.empty()) {
      int temp = forward.top();
      reverse.push(temp);
      forward.pop();
    }

    if (reverse.empty()) {
      throw "Stack has no items";
    }

    reverse.pop();
  }

  int peek() {
    while (!forward.empty()) {
      int temp = forward.top();
      reverse.push(temp);
      forward.pop();
    }

    if (reverse.empty()) {
      throw "Stack has no items";
    }

    return reverse.top();
  }

private:
  stack<int> forward;
  stack<int> reverse;
};

int main() {

  try {
    QueueWithStacks test;

    const int size = 7;
    int list[size] = {6, 12, 3, 4, 5, 6, 2};

    for (int i = 0; i < size; ++i) {
      test.push(list[i]);
    }

    cout << test.peek();

  } catch (const char* e) {
    cout << e;
  }

  return 0;

  return 0;
}