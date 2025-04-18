using System;
using System.Collections.Generic;

class TrieNode
{
    public Dictionary<char, TrieNode> Children;
    public bool IsEndOfWord;

    public TrieNode()
    {
        Children = new Dictionary<char, TrieNode>();
        IsEndOfWord = false;
    }
}

class Trie
{
    private TrieNode root;

    public Trie()
    {
        root = new TrieNode();
    }

    // Insert a word into the trie
    public void Insert(string word)
    {
        TrieNode node = root;
        foreach (char c in word)
        {
            if (!node.Children.ContainsKey(c))
            {
                node.Children[c] = new TrieNode();
            }
            node = node.Children[c];
        }
        node.IsEndOfWord = true;
    }

    // Check if any word in the trie starts with the given prefix
    public bool StartsWith(string prefix)
    {
        TrieNode node = root;
        foreach (char c in prefix)
        {
            if (!node.Children.ContainsKey(c))
            {
                return false;
            }
            node = node.Children[c];
        }
        return true;
    }
}

class Solution
{
    public static void Main(string[] args)
    {
        // Get the number of words from the user
        Console.WriteLine("Enter the number of words:");
        int n = int.Parse(Console.ReadLine()); 

        Trie trie = new Trie();

        Console.WriteLine($"Enter {n} words (one word per line):");
        // Insert words into the trie
        for (int i = 0; i < n; i++)
        {
            string word = Console.ReadLine();
            trie.Insert(word);
        }

        // Get the number of queries
        Console.WriteLine("Enter the number of queries:");
        int q = int.Parse(Console.ReadLine()); 

        Console.WriteLine($"Enter {q} queries (one prefix per line):");
        // Process each query
        for (int i = 0; i < q; i++)
        {
            string prefix = Console.ReadLine();
            if (trie.StartsWith(prefix))
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }
    }
}
