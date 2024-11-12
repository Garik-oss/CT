#include <iostream>
#include <vector>

class Graph {
public:
    int vertices;  // Number of pupils
    std::vector<int> degree;  // List of degrees for each pupil

    // Constructor to initialize the graph
    Graph(int v) : vertices(v) {
        degree.resize(v, 0);  // Initialize degrees to 0
    }

    // Function to set the degree of each pupil (vertex)
    void setDegrees(const std::vector<int>& degrees) {
        if (degrees.size() != vertices) {
            std::cerr << "Error: Degree list size does not match number of vertices!" << std::endl;
            return;
        }
        degree = degrees;
    }

    // Function to check if the sum of degrees is even or odd
    bool isDegreeSumEven() {
        int sum = 0;
        for (int i = 0; i < vertices; ++i) {
            sum += degree[i];
        }
        return (sum % 2 == 0);
    }

    // Function to display the degree of each pupil
    void displayDegrees() {
        for (int i = 0; i < vertices; ++i) {
            std::cout << "Pupil " << i + 1 << " has " << degree[i] << " friends." << std::endl;
        }
    }
};

int main() {
    int totalPupils = 30;
    
    // Degree distribution as per the problem
    std::vector<int> degreeDistribution = {3, 3, 3, 3, 3, 3, 3, 3, 3,  // 9 pupils with 3 friends
                                           4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  // 11 pupils with 4 friends
                                           5, 5, 5, 5, 5, 5, 5, 5, 5, 5,  // 10 pupils with 5 friends
                                          };

    Graph g(totalPupils);
    g.setDegrees(degreeDistribution);

    // Check if the degree sum is even
    if (g.isDegreeSumEven()) {
        std::cout << "The degree sum is even, it might be possible to construct the graph.\n";
    } else {
        std::cout << "The degree sum is odd, it is impossible to construct the graph.\n";
    }

    return 0;
}
