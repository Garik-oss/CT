using System;
using System.Collections.Generic;

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution {
    private int cameraCount = 0; // To keep track of the number of cameras used

    public int MinCameraCover(TreeNode root) {
        if (root == null) return 0;

        // Start the DFS traversal to determine the minimum cameras required
        if (PostOrderTraversal(root) == 0) {
            cameraCount++;
        }

        return cameraCount;
    }

    // Return values:
    // 0 = node is not covered
    // 1 = node is covered but not monitored
    // 2 = node has a camera
    private int PostOrderTraversal(TreeNode node) {
        if (node == null) {
            return 1; // If the node is null, it's considered covered
        }

        int left = PostOrderTraversal(node.left);
        int right = PostOrderTraversal(node.right);

        // If any of the children is not covered, we place a camera on this node
        if (left == 0 || right == 0) {
            cameraCount++;
            return 2; // This node has a camera
        }

        // If any of the children has a camera, the current node is covered but not monitored
        if (left == 2 || right == 2) {
            return 1; // This node is covered but not monitored
        }

        // If neither child has a camera and they are both covered, this node is not covered
        return 0; // This node is not covered
    }

    // Helper method to build tree from level-order input
    public TreeNode BuildTreeFromLevelOrder(List<string> nodes) {
        if (nodes == null || nodes.Count == 0 || nodes[0] == "null") return null;

        Queue<TreeNode> queue = new Queue<TreeNode>();
        TreeNode root = new TreeNode(int.Parse(nodes[0]));
        queue.Enqueue(root);
        int i = 1;

        while (i < nodes.Count) {
            TreeNode current = queue.Dequeue();

            if (nodes[i] != "null") {
                current.left = new TreeNode(int.Parse(nodes[i]));
                queue.Enqueue(current.left);
            }
            i++;

            if (i < nodes.Count && nodes[i] != "null") {
                current.right = new TreeNode(int.Parse(nodes[i]));
                queue.Enqueue(current.right);
            }
            i++;
        }

        return root;
    }
}

public class Program {
    public static void Main() {
        // Read user input for the tree in level-order form
        Console.WriteLine("Enter the nodes of the binary tree in level-order (comma-separated), with 'null' for missing nodes:");
        string input = Console.ReadLine();
        List<string> nodes = new List<string>(input.Split(','));

        Solution solution = new Solution();
        TreeNode root = solution.BuildTreeFromLevelOrder(nodes);
        int result = solution.MinCameraCover(root);

        Console.WriteLine("Minimum number of cameras needed: " + result);
    }
}
