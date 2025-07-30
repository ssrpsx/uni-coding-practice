#include <bits/stdc++.h>

class TrieNode
{
public:
    TrieNode *children[26];

    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

void ft_insert(TrieNode *root, const std::string &word)
{
    TrieNode *current = root;

    for (char c : word)
    {
        if (current->children[c - 'a'] == nullptr)
        {
            TrieNode *newNode = new TrieNode();
            current->children[c - 'a'] = newNode;
        }

        current = current->children[c - 'a'];
    }

    current->isEnd = true;
}

bool ft_search(TrieNode *root, const std::string &word)
{
    if (root == nullptr)
        return false;

    TrieNode *current = root;

    for (char c : word)
    {
        if (current->children[c - 'a'] == nullptr)
            return false;

        current = current->children[c - 'a'];
    }

    return current->isEnd;
}

bool ft_isPrefix(TrieNode *root, const std::string &word)
{
    if (root == nullptr)
        return false;

    TrieNode *current = root;

    for (char c : word)
    {
        if (current->children[c - 'a'] == nullptr)
            return false;

        current = current->children[c - 'a'];
    }

    return true;
}