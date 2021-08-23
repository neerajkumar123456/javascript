using System;
using System.Collections.Generic;
 
class GFG
{
    readonly public static int SIZE = 26;
    public class TrieNode
    {
        public TrieNode []children = new TrieNode[SIZE];
     
        public bool isLeaf;
         
        public TrieNode()
        {
            isLeaf = false;
            for (int i = 0 ; i < SIZE ; i++)
                    children[i] = null;
        }
    }
    static TrieNode root;
     
    static void insert(TrieNode root, String Key)
    {
        int n = Key.Length;
        TrieNode pCrawl = root;
     
        for (int i = 0; i < n; i++)
        {
            int index = Key[i] - 'a';
     
            if (pCrawl.children[index] == null)
                pCrawl.children[index] = new TrieNode();
     
            pCrawl = pCrawl.children[index];
        }
     
        pCrawl.isLeaf = true;
    }
     
    static List<int> findPrefix(TrieNode root, String key)
    {
        List<int> prefixPositions = new List<int>();
        int level;
        TrieNode pCrawl = root;
     
        for (level = 0; level < key.Length; level++)
        {
            int index = key[level] - 'a';
            if (pCrawl.isLeaf == true)
                prefixPositions.Add(level);
            if (pCrawl.children[index] == null)
                return prefixPositions;
     
            pCrawl = pCrawl.children[index];
        }
        if (pCrawl != null && pCrawl.isLeaf)
            prefixPositions.Add(level);
         
        return prefixPositions;
    }
     
    static bool isPossible(TrieNode root, String word)
    {
        List<int> prefixPositions1 = findPrefix(root, word);
     
        if (prefixPositions1.Count==0)
            return false;
        foreach (int len1 in prefixPositions1)
        {
            String restOfSubstring = word.Substring(len1,
                                        word.Length-len1);
            List<int> prefixPositions2 = findPrefix(root,
                                        restOfSubstring);
            foreach (int len2 in prefixPositions2)
            {
                 
                // check if word formation is possible
                if (len1 + len2 == word.Length)
                    return true;
            }
        }
        return false;
    }
     
    
    public static void Main(String []args)
    {
        String[] dictionary = {"news", "newspa", "paper", "geek"};
     
        String word = "newspaper";
        root = new TrieNode();
        for (int i = 0; i < dictionary.Length; i++)
            insert(root, dictionary[i]);
     
        if(isPossible(root, word))
            Console.WriteLine( "Yes");
        else
            Console.WriteLine("No");
    }