using System;
using System.Collections.Generic;

class TrieNode
{
    public Dictionary<char, TrieNode> Children = new Dictionary<char, TrieNode>();
    public bool IsEndOfWord = false;
}

class Trie
{
    private TrieNode root;

    public Trie()
    {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    public void Insert(string word)
    {
        TrieNode currentNode = root;
        foreach (char c in word)
        {
            if (!currentNode.Children.ContainsKey(c))
            {
                currentNode.Children[c] = new TrieNode();
            }
            currentNode = currentNode.Children[c];
        }
        currentNode.IsEndOfWord = true;
    }

    // Helper function to find all words in the Trie
    private void FindWords(TrieNode node, string currentWord, List<string> result)
    {
        if (node.IsEndOfWord)
        {
            result.Add(currentWord);
        }

        foreach (var child in node.Children)
        {
            FindWords(child.Value, currentWord + child.Key, result);
        }
    }

    // Method to find the longest and shortest words
    public List<string> FindLongestAndShortestWords()
    {
        List<string> words = new List<string>();
        FindWords(root, "", words);

        if (words.Count == 0)
            return words;

        string shortest = words[0];
        string longest = words[0];

        // Find shortest and longest
        foreach (string word in words)
        {
            if (word.Length < shortest.Length)
            {
                shortest = word;
            }
            if (word.Length > longest.Length)
            {
                longest = word;
            }
        }

        // If shortest and longest are the same, return all words
        if (shortest == longest)
        {
            return words;
        }

        // Otherwise, return shortest and longest
        List<string> result = new List<string> { shortest, longest };
        return result;
    }
}

class Program
{
    static void Main()
    {
        Trie trie = new Trie();

        // Insert words into the trie
        trie.Insert("apple");
        trie.Insert("bat");
        trie.Insert("ball");
        trie.Insert("batman");
        trie.Insert("ant");

        // Find longest and shortest words
        List<string> result = trie.FindLongestAndShortestWords();

        // Print result
        Console.WriteLine("Result:");
        foreach (string word in result)
        {
            Console.WriteLine(word);
        }
    }
}
