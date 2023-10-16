#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V;
    vector<int> *adj;

    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Since it's an undirected graph
    }

    void DFS(int v, vector<bool> &visited) {
        visited[v] = true;
        for (int i = 0; i < adj[v].size(); i++) {
            if (!visited[adj[v][i]]) {
                DFS(adj[v][i], visited);
            }
        }
    }

    int countConnectedComponents() {
        vector<bool> visited(V, false);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                DFS(i, visited);
            }
        }
        return count;
    }
};

int findConnectedComponents(int A, vector<vector<int> > &B) {
    Graph g(A);
    for (int i = 0; i < B.size(); i++) {
        g.addEdge(B[i][0] - 1, B[i][1] - 1);
    }
    return g.countConnectedComponents();
}


/*
Time Complexity: The DFS algorithm has a time complexity of O(V + E), where V is the number of vertices and E is the number of edges. In the worst case, it's O(A + |B|).
Space Complexity: The space complexity is O(V + E) for the graph representation and O(V) for the visited array. In the worst case, it's O(A + |B|) for space.
*/
int main() {
    int A = 4;
    vector<vector<int>> B = {{1, 2}, {2, 3}};
    int result = findConnectedComponents(A, B);
    cout << "Output: " << result << endl; // Output: 2

    A = 3;
    B = {{1, 2}, {2, 1}};
    result = findConnectedComponents(A, B);
    cout << "Output: " << result << endl; // Output: 2

    return 0;
}
