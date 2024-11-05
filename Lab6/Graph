#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <string>

using namespace std;

class Graph {
private:
    unordered_map<string, list<string>> adjList;

public:
    void addEdge(const string& vertex1, const string& vertex2) {
        adjList[vertex1].push_back(vertex2);
    }

    string findNoOutgoingVertex() {
        for (const auto& vertex : adjList) {
            // If the vertex has no outgoing edges
            if (vertex.second.empty()) {
                return vertex.first;
            }
        }
        return "-1";
    }

    void addVertex(const string& vertex) {
        if (adjList.find(vertex) == adjList.end()) {
            adjList[vertex] = list<string>();
        }
    }
};

int main() {
    Graph g;

    int n = 4;
    vector<pair<string, string>> edges = {{"a", "b"}, {"c", "b"}, {"d", "c"}, {"b", "a"}};

    g.addVertex("a");
    g.addVertex("b");
    g.addVertex("c");
    g.addVertex("d");

    for (const auto& edge : edges) {
        g.addEdge(edge.first, edge.second);
    }

    string result = g.findNoOutgoingVertex();
    cout << result << endl;

    return 0;
}
