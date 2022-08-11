// all standard problems for placement 
// =================================================================================================
 //=================================================================================================
//  ==================================================================================================
// Linked List 

// =================================================================================================
//  =================================================================================================
//  ==================================================================================================

// problem 1. 




// =================================================================================================
//  =================================================================================================
//  ==================================================================================================

// Array 
// =================================================================================================
//  =================================================================================================
//  ==================================================================================================
 
// Problem 1. Spiral matrix 
  
vector<int> spiralOrder(vector<vector<int> >& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;
  
    if (m == 0)
        return ans;
  
    vector<vector<bool> > seen(m, vector<bool>(n, false));
    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };
  
    int x = 0, y = 0, di = 0;
  
    // Iterate from 0 to m * n - 1
    for (int i = 0; i < m * n; i++) {
        ans.push_back(matrix[x][y]);
        // on normal geeksforgeeks ui page it is showing
        // 'ans.push_back(matrix[x])' which gets copied as
        // this only and gives error on compilation,
        seen[x][y] = true;
        int newX = x + dr[di];
        int newY = y + dc[di];
  
        if (0 <= newX && newX < m && 0 <= newY && newY < n
            && !seen[newX][newY]) {
            x = newX;
            y = newY;
        }
        else {
            di = (di + 1) % 4;
            x += dr[di];
            y += dc[di];
        }
    }
    return ans;
}
//  O(n) 
// ling-> https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
//   .......................................................................................

// Method 2 
void spiralPrint(int m, int n, int a[R][C])
{
    int i, k = 0, l = 0;
  
    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
  
    while (k < m && l < n) {
        /* Print the first row from
               the remaining rows */
        for (i = l; i < n; ++i) {
            cout << a[k][i] << " ";
        }
        k++;
  
        /* Print the last column
         from the remaining columns */
        for (i = k; i < m; ++i) {
            cout << a[i][n - 1] << " ";
        }
        n--;
  
        /* Print the last row from
                the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                cout << a[m - 1][i] << " ";
            }
            m--;
        }
  
        /* Print the first column from
                   the remaining columns */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                cout << a[i][l] << " ";
            }
            l++;
        }
    }
}
//  O(m*n);
// ...................................................................


// Problem 2 






// =================================================================================================
//  =================================================================================================
//  ==================================================================================================

// MATRIX  
// =================================================================================================
//  =================================================================================================
//  ==================================================================================================
 
// Possible knight move at a time

#include<bits/stdc++.h> 
using namespace std; 

int possibleMoves(vector<vector<int>> grid) {
    int count =0; 
    
    int dx[8] = {1,2,1,-1,-2,-2,-1,2}; 
    int dy[8] = {2,-1,-2,-2,-1,1,2,1}; 
    
    int p = 0, q = 0; 
    int m = grid.size(), n = grid[0].size(); 
    
    for(int i =0; i<8; ++i) {
        int newX = p + dx[i]; 
        int newY = q + dy[i]; 
            
        if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==0) 
                count++; 
    }
    
    return count; 
}



int main() {
    
    vector<vector<int>> res(8, vector(8,0)); 
    
    cout<<possibleMoves(res); 
    
    return 0; 
    
}
// ........................................................................................


// Problem 2 The Knight's tour Problem 



#include<bits/stdc++.h> 
using namespace std; 

int ktUtil(int x, int y, int movi, vector<vector<int>> &sol, int dx[8], int dy[8]);
bool isSafe(int x, int y, vector<vector<int>> chess) {
     return (x>=0 && x<8 && y>=0 && y<8 && chess[x][y]==-1); 
}

int KnightTour(vector<vector<int>> &chessBoard) {
    
    int dx[8] ={2,2,-2,-1,-2,-2,-1,1}; 
    int dy[8] ={1,-1,1,-2,-1,1,2,2}; 
    
    int movi = 1; 
    chessBoard[0][0] = 0; 
    
    if(ktUtil(0,0,movi,chessBoard,dx,dy)==0)
      return 0; 
     
     return 1; 
    
    
}

int ktUtil(int x, int y, int movi, vector<vector<int>> &sol, int dx[8], int dy[8]) {
    
    
    // int next_x, next_y; 
    
    if(8*8==movi) return 1; 
    
    
    for(int k =0; k<8; ++k) {
        int next_x = dx[k] + x; 
        int next_y = dy[k] + y; 
       
       if(isSafe(next_x, next_y,sol)==1) {
           sol[next_x][next_y] = movi; 
           if(ktUtil(next_x,next_y,movi+1,sol,dx,dy)) return 1; 
           else {
               sol[next_x][next_y] = -1;  
           }
       } 
    }
    return -1; 
}



int main() {
    
    vector<vector<int>> res(8, vector(8,-1)); 
    
    cout<<KnightTour(res)<<endl; 
    
    return 0; 
    
}
// Link -> backtarcking -> https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/
//................................................................................................


// Problem 3.  Minimum steps to reach target Knight tour 
// method 1 BFS
// C++ program to find minimum steps to reach to
// specific cell in minimum moves by Knight
#include <bits/stdc++.h>
using namespace std;

// structure for storing a cell's data
struct cell {
	int x, y;
	int dis;
	cell() {}
	cell(int x, int y, int dis)
		: x(x), y(y), dis(dis)
	{
	}
};

// Utility method returns true if (x, y) lies
// inside Board
bool isInside(int x, int y, int N)
{
	if (x >= 1 && x <= N && y >= 1 && y <= N)
		return true;
	return false;
}

// Method returns minimum step
// to reach target position
int minStepToReachTarget(
	int knightPos[], int targetPos[],
	int N)
{
	// x and y direction, where a knight can move
	int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
	int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

	// queue for storing states of knight in board
	queue<cell> q;

	// push starting position of knight with 0 distance
	q.push(cell(knightPos[0], knightPos[1], 0));

	cell t;
	int x, y;
	bool visit[N + 1][N + 1];

	// make all cell unvisited
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			visit[i][j] = false;

	// visit starting state
	visit[knightPos[0]][knightPos[1]] = true;

	// loop until we have one element in queue
	while (!q.empty()) {
		t = q.front();
		q.pop();

		// if current cell is equal to target cell,
		// return its distance
		if (t.x == targetPos[0] && t.y == targetPos[1])
			return t.dis;

		// loop for all reachable states
		for (int i = 0; i < 8; i++) {
			x = t.x + dx[i];
			y = t.y + dy[i];

			// If reachable state is not yet visited and
			// inside board, push that state into queue
			if (isInside(x, y, N) && !visit[x][y]) {
				visit[x][y] = true;
				q.push(cell(x, y, t.dis + 1));
			}
		}
	}
}

// Driver code to test above methods
int main()
{
	int N = 30;
	int knightPos[] = { 1, 1 };
	int targetPos[] = { 30, 30 };
	cout << minStepToReachTarget(knightPos, targetPos, N);
	return 0;
}

// .... method 2 ..... DFS........














// =================================================================================================
//  =================================================================================================
//  ==================================================================================================
// Dynamic Programming 
// =================================================================================================
//  =================================================================================================
//  ==================================================================================================

// Problem 1. House rober -> 

int Util(vector<int>& nums, int i , vector<int>& dp)  {
        
        if(i>=nums.size()) return 0; 
        
        if(dp[i]!=-1) return dp[i]; 
        
        int including = nums[i] + Util(nums,i+2,dp); 
        int excluding = Util(nums,i+1,dp); 
        
        return dp[i] =max(including,excluding); 
    }
    
    
    int rob(vector<int>& nums) {
        
        int n = nums.size(); 
        vector<int> dp(n,-1);
        
           return Util(nums,0,dp); 
        
    }






// =================================================================================================
//  =================================================================================================
//  ==================================================================================================

// Recursion & Backtracking
// =================================================================================================
//  =================================================================================================
//  ==================================================================================================




// =================================================================================================
//  =================================================================================================
//  ==================================================================================================

// Stack And Queue 
// =================================================================================================
//  =================================================================================================
//  ==================================================================================================




// =================================================================================================
//  =================================================================================================
//  ==================================================================================================

// String 
// =================================================================================================
//  =================================================================================================
//  ==================================================================================================

// Problem 1. Print all substring of string  

void printSubstrings(string str)
{
 
    // First loop for starting index
    for (int i = 0; i < str.length(); i++) {
        string subStr;
        // Second loop is generating sub-string
        for (int j = i; j < str.length(); j++) {
            subStr += str[j];
            cout << subStr << endl;
        }
    }
}
complexity O(n*n) ; 
//......................................................................
// problem 2. print all subsequnces of string 

void printSubsequence(string input, string output)
{
    // Base Case
    // if the input is empty print the output string
    if (input.empty()) {
        cout << output << endl;
        return;
    }
 
    // output is passed with including
    // the Ist character of
    // Input string
    printSubsequence(input.substr(1), output + input[0]);
 
    // output is passed without
    // including the Ist character
    // of Input string
    printSubsequence(input.substr(1), output);
}
// Complexity(O(2^n)) 
.....................................................................
	
// Parmutation of Given String 
	
	void permute(string a, int l, int r) 
{ 
    // Base case 
    if (l == r) 
        cout<<a<<endl; 
    else
    { 
        // Permutations made 
        for (int i = l; i <= r; i++) 
        { 
  
            // Swapping done 
            swap(a[l], a[i]); 
  
            // Recursion called 
            permute(a, l+1, r); 
  
            //backtrack 
            swap(a[l], a[i]); 
        } 
    } 
} 






// =================================================================================================
//  =================================================================================================
//  ==================================================================================================

// Graph 
// =================================================================================================
//  =================================================================================================
//  ==================================================================================================




// =================================================================================================
//  =================================================================================================
//  ==================================================================================================

//Trie
// =================================================================================================
//  =================================================================================================
//  ==================================================================================================



