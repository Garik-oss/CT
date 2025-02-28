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
    public IList<int> InorderTraversal(TreeNode root) {
        List<int> result = new List<int>();
        InorderHelper(root, result);
        return result;
    }

    private void InorderHelper(TreeNode node, List<int> result) {
        if (node == null) {
            return;
        }

        // Traverse left subtree
        InorderHelper(node.left, result);

        // Visit the root
        result.Add(node.val);

        // Traverse right subtree
        InorderHelper(node.right, result);
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

// Driver code
public class Program {
    public static void Main() {
        // Read user input for the tree in level-order form
        Console.WriteLine("Enter the nodes of the binary tree in level-order (comma-separated), with 'null' for missing nodes:");
        string input = Console.ReadLine();
        List<string> nodes = new List<string>(input.Split(','));

        Solution solution = new Solution();
        TreeNode root = solution.BuildTreeFromLevelOrder(nodes);
        IList<int> result = solution.InorderTraversal(root);

        Console.WriteLine("Inorder Traversal: " + string.Join(", ", result));
    }
}
