#include <iostream>
#include <vector>
using namespace std;

/*
Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

Thought Process:

Edge cases: We are garunteed to receive an NxN matrix? We should not account for the case that we dont recieve one?
Each pixel in the imagew being 4 bytes, does that have something to do with some sort of optimization of the problem?

First Approach: Iterative Rotations

After drawing out a few examples adn thinking about the problem, we understand that we can approach this layer by layer. 
First let's just consider what happens on one layer of the array. The items at the top left corner go to the top right corner, 
the top right corner gotes to the bottom right corner and so on and so forth.

Additionally, we will have four pointers each traversing a part of the layer. We will have a pointer traversing the top row, bottom, left and right.
Look at this video for a more in depth explanation: https://backtobackswe.com/platform/content/rotating-a-2d-matrix 
This takes O(NxN) time (linear time since the input is a 2D array) and O(1) space.
*/

void printMatrix(const vector<vector<int>>& matrix) {

  for(vector<int> rows : matrix) {
    for(int elem : rows) {
      cout << elem << "\t";
    }
    cout << "\n";
  }
}

void initMatrix(vector<vector<int>>& matrix) {
  const int N = 5;
  int counter = 1;

  for(int rows = 0; rows < N; ++rows) {
    for(int cols = 0; cols < N; ++cols) {
      matrix[rows][cols] = counter;
      counter++;
    }
  }
}

void printLineBreak() {
  cout << "-----------------------------------\n";
}

void rotateMatrixIterativeRotations(vector<vector<int>>& matrix) {

  if( matrix.size() != matrix[0].size()) { throw "Invalid matrix, must be NxN"; }

  int N = matrix.size();
  int size = N-1;

  for(int layer = 0; layer < N/2; ++layer) {
    for(int i = layer; i < size-layer; ++i) {
      int top = matrix[layer][i];
      int right = matrix[i][size-layer];
      int bottom = matrix[size-layer][size-i];
      int left = matrix[size-i][layer];

      matrix[layer][i] = left;
      matrix[i][size-layer] = top;
      matrix[size-layer][size-i] = right;
      matrix[size-i][layer] = bottom;
    }
  }
}

/*
Second Approach: Transpose and Flip
This takes O(NxN) time (linear time since the input is a 2D array) and O(1) space.
*/

void tranpose(vector<vector<int>>& matrix) {

  int N = matrix.size();
  
  for(int i = 0; i < N; ++i) {
    for(int j = i; j < N; ++j) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
}

void flipCols(vector<vector<int>>& matrix) {

  int N = matrix.size();
  
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N/2; ++j) {
      int temp = matrix[i][j];
      matrix[i][j] =  matrix[i][N-1-j];
      matrix[i][N-1-j] = temp;
    }
  }
}

void rotateMatrixTransposeAndFlip(vector<vector<int>>& matrix) {
  if( matrix.size() != matrix[0].size()) { throw "Invalid matrix, must be NxN"; }
  tranpose(matrix);
  flipCols(matrix);
}


int main() {

  vector<vector<int>> matrix(5, vector<int>(5, 0));
  printLineBreak();
  initMatrix(matrix);
  cout << "OG Matrix\n";
  printLineBreak();
  printMatrix(matrix);
  printLineBreak();
  try {
    rotateMatrixTransposeAndFlip(matrix);
    cout << "Rotated Matrix\n";
    printLineBreak();
    printMatrix(matrix);
  } catch(const char* msg) {
    cerr << msg;
  }
  

  return 0;
}