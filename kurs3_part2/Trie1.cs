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

    // 1. Add word
    public void Insert(string word)
    {
        TrieNode current = root;
        foreach (char c in word)
        {
            if (!current.Children.ContainsKey(c))
            {
                current.Children[c] = new TrieNode();
            }
            current = current.Children[c];
        }
        current.IsEndOfWord = true;
    }

    // 2. Search word
    public bool Search(string word)
    {
        TrieNode current = root;
        foreach (char c in word)
        {
            if (!current.Children.ContainsKey(c))
                return false;
            current = current.Children[c];
        }
        return current.IsEndOfWord;
    }

    // 3. Delete word
    public bool Delete(string word)
    {
        return DeleteHelper(root, word, 0);
    }

    private bool DeleteHelper(TrieNode current, string word, int index)
    {
        if (index == word.Length)
        {
            if (!current.IsEndOfWord)
                return false;
            current.IsEndOfWord = false;
            return current.Children.Count == 0;
        }

        char c = word[index];
        if (!current.Children.ContainsKey(c))
            return false;

        bool shouldDeleteCurrentNode = DeleteHelper(current.Children[c], word, index + 1);

        if (shouldDeleteCurrentNode)
        {
            current.Children.Remove(c);
            return current.Children.Count == 0 && !current.IsEndOfWord;
        }

        return false;
    }
}

class Program
{
    static void Main()
    {
        Trie trie = new Trie();

        // Add values to Trie
        trie.Insert("apple");
        trie.Insert("app");
        trie.Insert("bat");
        trie.Insert("ball");

        Console.WriteLine("Search Results:");
        Console.WriteLine($"Search 'apple': {trie.Search("apple")}");
        Console.WriteLine($"Search 'app': {trie.Search("app")}");
        Console.WriteLine($"Search 'bat': {trie.Search("bat")}");
        Console.WriteLine($"Search 'cat': {trie.Search("cat")}");

        Console.WriteLine("\nDeleting 'app'...");
        trie.Delete("app");
        Console.WriteLine($"Search 'app' after delete: {trie.Search("app")}");
        Console.WriteLine($"Search 'apple' (should still exist): {trie.Search("apple")}");

        Console.WriteLine("\nDeleting 'bat'...");
        trie.Delete("bat");
        Console.WriteLine($"Search 'bat' after delete: {trie.Search("bat")}");
        Console.WriteLine($"Search 'ball' (should still exist): {trie.Search("ball")}");
    }
}
