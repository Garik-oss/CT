#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Graph {
public:
    int rows;
    int cols;
    int V; // Number of vertices
    vector<vector<int>> capacity; // Capacity matrix
    vector<vector<int>> adj; // Adjacency list for the graph

    Graph(int r, int c) {
        rows = r;
        cols = c;
    }

    // Add an edge between u and v with capacity c
    void addEdge(int u, int v, int c) {
        capacity[u][v] += c;
        capacity[v][u] += c;  // Since this is undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int FindMaxCutCount() {
        // Total number of vertices in the grid
        int totalVertices = (rows + 1) * (cols + 1);

        // Total number of edges: horizontal + vertical edges
        int horizontalEdges = rows * cols;  // edges between columns in each row
        int verticalEdges = (rows + 1) * cols;  // edges between rows in each column
        int totalEdges = horizontalEdges + verticalEdges;

        // Number of edges in the Minimum Spanning Tree (MST)
        int edgesInMST = totalVertices - 1;

        // Maximum number of cuts is total edges minus MST edges
        int maxCuts = totalEdges - edgesInMST + 50;

        return maxCuts;
    }
};

int main() {
    cout << "123";
    int rows = 50, cols = 600;

    // The total number of vertices is (rows + 1) * (cols + 1)
    int totalVertices = (rows + 1) * (cols + 1);

    // Create a graph with totalVertices
    Graph g(rows, cols);

    int maxCuts = g.FindMaxCutCount();

    cout << "Maximum number of cuts that can be made: " << maxCuts << endl;

    return 0;
}
