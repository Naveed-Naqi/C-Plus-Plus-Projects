#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be
composed of several stacks and should create a new stack once the previous one exceeds capacity.
SetOfStacks. push () and SetOfStacks. pop() should behave identically to a single stack
(that is, pop ( ) should return the same values as it would if there were just a single stack).

FOLLOW UP

Implement a function popAt (int index) which performs a pop operation on a specific substack. 

First Approach: 
We could potentially use a linked list instaed of a vector to make the set of stacks more efficent, but for now lets just stick with a vector for simplicitys sake.
*/

class SetOfStacks {
public:
  SetOfStacks(size_t size) : _size(size), _curr_stack_index(0){};

  void push(const int& val) {
    // if (_list_of_stacks[_curr_stack_index].size() == _size) {
    //   _curr_stack_index++;
    //   _list_of_stacks[_curr_stack_index].push(val);
    //   _size = _list_of_stacks[_curr_stack_index].size();
    // } else {
    //   _list_of_stacks[_curr_stack_index].push(val);
    // }
  }

private:
  vector<stack<int>> _list_of_stacks;
  size_t _size;
  size_t _curr_stack_index;
};

int main() {

  try {
    SetOfStacks test(2);

    const int size = 7;
    int list[size] = {6, 12, 3, 4, 5, 6, 2};

    for (int i = 0; i < size; ++i) {
      test.push(list[i]);
      break;
    }

  } catch (const char* e) {
    cout << e;
  }

  return 0;
}