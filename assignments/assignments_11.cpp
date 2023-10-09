// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;

// time complexity of O(4^N) and space complexity is O(N^2) 
bool canReachDestination(vector<vector<int>>& maze, vector<vector<bool>>& visited, int x, int y) {
  // Check if the current cell is out of bounds or is blocked.
  if (x < 0 || x >= maze.size() || y < 0 || y >= maze[0].size() || maze[x][y] == 0 || visited[x][y]) {
    return false;
  }

  // Mark the current cell as visited.
  visited[x][y] = true;

  // Check if the destination cell is reached.
  if (x == maze.size() - 1 && y == maze[0].size() - 1) {
    return true;
  }

  // Recursively check the neighboring cells.
  return canReachDestination(maze, visited, x + 1, y) || canReachDestination(maze, visited, x - 1, y) || canReachDestination(maze, visited, x, y + 1) || canReachDestination(maze, visited, x, y - 1);
}

bool isPathExist(vector<vector<int>>& maze, int N) {
  // Create a boolean matrix to keep track of visited cells.
  vector<vector<bool>> visited(N, vector<bool>(N, false));

  // Start the search from the source cell.
  return canReachDestination(maze, visited, 0, 0);
}


int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
                             
    // vector<vector<int>> maze = {{1, 0},
    //                          {1, 0}};

  int N = maze.size();

  bool result = isPathExist(maze, N);
  cout << result;

    return 0;
}
