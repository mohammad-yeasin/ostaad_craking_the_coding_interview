#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> graph;
int count = 0;

void dfs(int node, int parent, vector<int>& A, int good_nodes, int C) {
    if (A[node - 1] == 1) {
        good_nodes += 1;
    }

    if (good_nodes > C) {
        return;
    }

    if (graph[node].size() == 1 && node != 1) {
        count += 1;
        return;
    }

    for (int child : graph[node]) {
        if (child != parent) {
            dfs(child, node, A, good_nodes, C);
        }
    }
}

//The time complexity of this solution is O(N) and the space complexity is O(N) 
int countGoodPaths(vector<int>& A, vector<vector<int>>& edges, int C) {
    count = 0;
    graph.clear();

    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0, A, 0, C);
    return count;
}

int main() {
    // Example 1
    vector<int> A1 = {0, 1, 0, 1, 1, 1};
    vector<vector<int>> B1 = {{1, 2}, {1, 5}, {1, 6}, {2, 3}, {2, 4}};
    int C1 = 1;
    cout << countGoodPaths(A1, B1, C1) << endl;  // Output: 3

    // Example 2
    vector<int> A2 = {0, 1, 0, 1, 1, 1};
    vector<vector<int>> B2 = {{1, 2}, {1, 5}, {1, 6}, {2, 3}, {2, 4}};
    int C2 = 2;
    cout << countGoodPaths(A2, B2, C2) << endl;  // Output: 4

    return 0;
}
