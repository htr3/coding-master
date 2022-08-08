// all standard problems for placement 

// Linked List 




// Array 
 
// Problem 1. Spiral matrix 
  
void print(int arr[R][C], int i, int j, int m, int n)
{
    // If i or j lies outside the matrix
    if (i >= m or j >= n)
        return;
  
    // Print First Row
    for (int p = j; p < n; p++)
        cout << arr[i][p] << " ";
  
    // Print Last Column
    for (int p = i + 1; p < m; p++)
        cout << arr[p][n - 1] << " ";
  
    // Print Last Row, if Last and
    // First Row are not same
    if ((m - 1) != i)
        for (int p = n - 2; p >= j; p--)
            cout << arr[m - 1][p] << " ";
  
    // Print First Column,  if Last and
    // First Column are not same
    if ((n - 1) != j)
        for (int p = m - 2; p > i; p--)
            cout << arr[p][j] << " ";
  
    print(arr, i + 1, j + 1, m - 1, n - 1);
}
// ling-> https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/

// Problem 2 



// Dynamic Programming 




// Recursion & Backtracking




// Stack And Queue 



// String 




// Graph 



//Trie



//
