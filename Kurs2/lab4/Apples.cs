using System;
using System.Collections.Generic;

class Program
{
    // Function to perform DFS and find the minimum steps required to collect all apples
    static int Dfs(int node, List<List<int>> tree, bool[] apples, bool[] visited)
    {
        visited[node] = true;
        int steps = 0;

        // Iterate over each child node of the current node
        foreach (int neighbor in tree[node])
        {
            if (!visited[neighbor])
            {
                int subTreeSteps = Dfs(neighbor, tree, apples, visited);

                // If the subtree has apples or steps to reach a node with apples, add the edge (i.e., the step)
                if (subTreeSteps > 0 || apples[neighbor])
                {
                    steps += subTreeSteps + 2; // +2 to account for moving to the neighbor and back
                }
            }
        }
        return steps;
    }

    static void Main()
    {
        // Input for the number of nodes
        Console.Write("Enter the number of nodes: ");
        int n = int.Parse(Console.ReadLine());

        // Initialize the tree adjacency list
        List<List<int>> tree = new List<List<int>>();
        for (int i = 0; i < n; i++)
        {
            tree.Add(new List<int>());
        }

        // Input for the tree edges
        Console.WriteLine("Enter the tree connections as pairs of nodes (enter 'done' to stop):");
        string input;
        while ((input = Console.ReadLine()) != "done")
        {
            var nodes = input.Split(',');
            int node1 = int.Parse(nodes[0].Trim());
            int node2 = int.Parse(nodes[1].Trim());

            // Add the bidirectional edges
            tree[node1].Add(node2);
            tree[node2].Add(node1);
        }

        // Input for the apples data
        bool[] apples = new bool[n];
        Console.WriteLine("Enter apple presence for each node (true if apple is present, false otherwise):");
        for (int i = 0; i < n; i++)
        {
            Console.Write($"Node {i}: ");
            apples[i] = bool.Parse(Console.ReadLine());
        }

        // Visited array to keep track of visited nodes
        bool[] visited = new bool[n];
        
        // Starting DFS from the root node (node 0)
        int result = Dfs(0, tree, apples, visited);
        
        // Output the result
        Console.WriteLine("Minimum steps to collect all apples: " + result);
    }
}
