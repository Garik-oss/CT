#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>  // For unordered_set
#include <random>
#include <algorithm>

using namespace std;

// Graph class to represent the acquaintanceship
class Graph {
public:
    int numStudents;                          // Total number of students
    vector<vector<int>> adjList;              // Adjacency list to store acquaintances

    // Constructor
    Graph(int n) : numStudents(n) {
        adjList.resize(numStudents);          // Resize the adjacency list
        createAcquaintances();
    }

    // Function to create acquaintances with random degrees
    void createAcquaintances() {
        random_device rd;                      // Random number generator
        mt19937 gen(rd());                     // Mersenne Twister engine
        uniform_int_distribution<> degreeDist(0, 68); // Distribution for degrees

        // Randomly assign degrees to each student
        vector<int> degrees(numStudents);
        for (int i = 0; i < numStudents; ++i) {
            degrees[i] = degreeDist(gen);
        }

        // Ensure at least 4 students have the same degree
        int targetDegree = degrees[0]; // Take the degree of the first student
        for (int i = 1; i < 4; ++i) {
            degrees[i] = targetDegree; // Set at least 4 students to have the same degree
        }

        // Set to ensure each student has a unique set of acquaintances
        for (int i = 0; i < numStudents; ++i) {
            unordered_set<int> acquaintances;

            // Randomly select unique acquaintances for each student
            while (acquaintances.size() < degrees[i]) {
                int acquaintance = degreeDist(gen); // Get a random acquaintance index
                if (acquaintance != i) { // Ensure a student does not know themselves
                    acquaintances.insert(acquaintance);
                }
            }

            // Convert set to vector for adjacency list representation
            adjList[i] = vector<int>(acquaintances.begin(), acquaintances.end());
        }
    }

    // Function to find students with the same number of acquaintances
    void findStudentsWithSameDegree() {
        // Map to count how many students have the same number of acquaintances
        unordered_map<int, int> degreeCount;

        // Calculate degrees
        for (int i = 0; i < numStudents; ++i) {
            int degree = adjList[i].size(); // Degree is the size of the adjacency list
            degreeCount[degree]++;
        }

        // Find and print degrees
        for (const auto& entry : degreeCount) {
            if (entry.second >= 4) { // We need at least 4 students with the same degree
                cout << "There are at least " << entry.second 
                     << " students with " << entry.first << " acquaintances." << endl;
            }
        }
    }
};

int main() {
    const int numStudents = 102; // Total number of students

    // Create a graph instance
    Graph schoolGraph(numStudents);

    // Find students with the same degree of acquaintances
    schoolGraph.findStudentsWithSameDegree();

    return 0;
}
