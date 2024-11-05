#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <vector>

using namespace std;

class Graph {
private:
    unordered_map<string, list<string>> adjList;  // Graph's adjacency list
    unordered_map<string, string> decisions;  // Map to store decisions (Guilty/NotGuilty)

public:
    // Add a vertex (person) to the graph
    void addVertex(const string& vertex) {
        if (adjList.find(vertex) == adjList.end()) {
            adjList[vertex] = list<string>();
        }
    }

    // Add an edge between two vertices (decisions)
    void addEdge(const string& vertex1, const string& vertex2) {
        adjList[vertex1].push_back(vertex2);
    }

    // Store the decision for a person (vertex)
    void addDecision(const string& person, const string& decision) {
        decisions[person] = decision;
    }

    // Find majority decision based on votes
    string findMajorityDecision() {
        int guiltyCount = 0;
        int notGuiltyCount = 0;

        // Traverse all people and count the votes
        for (const auto& entry : decisions) {
            if (entry.second == "Guilty") {
                guiltyCount++;
            } else if (entry.second == "NotGuilty") {
                notGuiltyCount++;
            }
        }

        if (guiltyCount >= notGuiltyCount) {
            return "Guilty";
        } else {
            return "NotGuilty";
        }
    }
};

int main() {
    Graph g;

    // Adding people (vertices) to the graph
    g.addVertex("Judge");
    g.addVertex("Alice");
    g.addVertex("Bob");
    g.addVertex("Charlie");
    g.addVertex("David");
    g.addVertex("Eve");

    // Adding decisions (edges)
    g.addDecision("Judge", "Guilty");
    g.addDecision("Alice", "Guilty");
    g.addDecision("Bob", "NotGuilty");
    g.addDecision("Charlie", "Guilty");
    g.addDecision("David", "NotGuilty");
    g.addDecision("Eve", "Guilty");

    // Find the majority decision
    string majorityDecision = g.findMajorityDecision();
    cout << "The majority decision is: " << majorityDecision << endl;

    return 0;
}
