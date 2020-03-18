#include <iostream>
#include <vector>
#include<bitset>
using namespace std;

/*
Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column are set to 0.

We must keep track of all the original zeros in the matrix beforore converting anything, otherwise our whole matrix will become full of zeros.

First Approach: Second Matrix

We can parse through the input matrix and create a second one that saves the locations 
of all the original zeros and changes the original matrix based on those locations of zeros.

This approach takes O(NxM) time and space.
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

void makeZero(vector<vector<int>>& matrix, int row, int col) {

  for(int i = 0; i < matrix.size(); ++i) {
    matrix[i][col] = 0;
  }

  for(int i = 0; i < matrix[row].size(); ++i) {
    matrix[row][i] = 0;
  }
}

void zeroMatrixSecondMatrix(vector<vector<int>>& matrix) {

  const int rows = matrix.size();
  const int cols = matrix[0].size();

  vector<vector<int>> aux_matrix(rows, vector<int>(cols, 0));

  for(int i = 0; i < rows; ++i) {
    for(int j = 0; j < cols; ++j) {
      if(matrix[i][j] == 0) {
        aux_matrix[i][j] = 1;
      }
    }
  }

  for(int i = 0; i < rows; ++i) {
    for(int j = 0; j < cols; ++j) {
      if(aux_matrix[i][j] == 1) {
        makeZero(matrix, i, j);
      }
    }
  }
}

/*
Second Approach: Two Bitsets

We don't really need to use another 2D array to keep track of the OG zeros because we don't need to know the exact position of each zero,
we just need to know that the row/col contained a zero at some position. So instead of using a 2D array we can use 2 arrays.
One to represent the cols and one to represent the rows.

We can use a bitset instead of an array because we only want to store whether the element is a 0 or not.

Space Complexity is O(N+M) and Time Complexity is O(NxM) where N is rows and M is cols
*/

void makeColsZero(vector<vector<int>>& matrix, int index) {
  for(int i = 0; i < matrix.size(); ++i) {
    matrix[i][index] = 0;
  }
}

void makeRowsZero(vector<vector<int>>& matrix, int index) {
  for(int i = 0; i < matrix[0].size(); ++i) {
    matrix[index][i] = 0;
  }
}

void zeroMatrixTwoBitsets(vector<vector<int>>& matrix) {

  const int rows = matrix.size();
  const int cols = matrix[0].size();

  vector<bool> aux_rows(rows, false);
  vector<bool> aux_cols(cols, false);


  for(int i = 0; i < rows; ++i) {
    for(int j = 0; j < cols; ++j) {
      if(matrix[i][j] == 0) {
        aux_cols[j] = true;
        aux_rows[i] = true;
      }
    } 
  }

  for (int i = 0; i < rows; ++i) {
    if(aux_rows[i]) {
      makeRowsZero(matrix, i);
    }
  }

  for (int j = 0; j < cols; ++j) {
    if(aux_cols[j]) {
      makeColsZero(matrix, j);
    }
  }
}

/*
Third Approach: Cheeky
This is essentially just an optimization we can make on the second appraoch.
Instead of creating new arrays to hold the indices of 0, we will use the row and col of the first zero we find in the array.

This way we can solve it in constant space and linear time.
*/

int main() {

  vector<vector<int>> matrix(5, vector<int>(5, 0));
  printLineBreak();
  initMatrix(matrix);
  matrix[2][3]=0;
  matrix[3][4]=0;
  cout << "OG Matrix\n";
  printLineBreak();
  printMatrix(matrix);
  printLineBreak();
  try {
    zeroMatrixSecondMatrix(matrix);
    cout << "Zero Matrix\n";
    printLineBreak();
    printMatrix(matrix);
  } catch(const char* msg) {
    cerr << msg;
  }



  return 0;
}