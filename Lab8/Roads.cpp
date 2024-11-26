#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    int V;  // Number of vertices (cities)
    vector<vector<int>> adj;  // Adjacency list representing the graph
    vector<int> discovery, low, parent;
    vector<bool> visited;
    
    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
        discovery.assign(V, -1);
        low.assign(V, -1);
        parent.assign(V, -1);
        visited.assign(V, false);
    }

    // Add an undirected edge between u and v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS function to find articulation points
    void dfs(int u, int &time, vector<bool>& articulationPoint) {
        visited[u] = true;
        discovery[u] = low[u] = time++;
        int children = 0;
        
        for (int v : adj[u]) {
            if (!visited[v]) {  // If v is not visited
                parent[v] = u;
                children++;
                
                dfs(v, time, articulationPoint);

                // After returning from dfs(v), update the low[u]
                low[u] = min(low[u], low[v]);

                // Check if u is an articulation point
                if ((parent[u] == -1 && children > 1) ||  // Root with two or more children
                    (parent[u] != -1 && low[v] >= discovery[u])) {  // Non-root condition
                    articulationPoint[u] = true;
                }
            } else if (v != parent[u]) {  // Back edge case
                low[u] = min(low[u], discovery[v]);
            }
        }
    }

    // Function to check if there exists a "secret town"
    bool hasSecretTown() {
        int time = 0;
        vector<bool> articulationPoint(V, false);
        
        // Call dfs for all unvisited vertices
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, time, articulationPoint);
            }
        }
        
        // Check if any articulation point exists
        for (int i = 0; i < V; i++) {
            if (articulationPoint[i]) {
                return true;  // If there's at least one articulation point
            }
        }
        
        return false;  // No articulation point found
    }
};

int main() {
    // Predefined graph data (cities and roads):
    int V = 5;  // Number of cities (vertices)
    int E = 5;  // Number of roads (edges)

    // Create graph with 5 cities
    Graph g(V);

    // Hardcoding the edges (roads between cities):
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    // Check if there exists a secret town (articulation point)
    if (g.hasSecretTown()) {
        cout << "Yes, there exists a secret town.\n";
    } else {
        cout << "No, there is no secret town.\n";
    }

    return 0;
}
