#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <memory>

using namespace std;


struct TrieNode {
    unordered_map<char, unique_ptr<TrieNode>> children;
    bool isEndOfWord = false;
};


class Trie {
public:
    TrieNode* root;

    Trie() : root(new TrieNode()) {}

    void insert(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = make_unique<TrieNode>();
            }
            curr = curr->children[c].get();
        }
        curr->isEndOfWord = true;
    }
};

class Solution {
public:
    
    unordered_map<string, vector<string>> memo;
    Trie trie;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (const string& word : wordDict) {
            trie.insert(word);
        }
        return backtrack(s);
    }

private:
    vector<string> backtrack(const string& s) {
        if (memo.count(s)) {
            return memo[s];
        }

        if (s.empty()) {
            return {""}; 
        }

        vector<string> results;
        TrieNode* curr = trie.root;
        
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (curr->children.find(c) == curr->children.end()) {
                break; 
            }
            curr = curr->children[c].get();

            if (curr->isEndOfWord) {
                string currentWord = s.substr(0, i + 1);
               
                vector<string> suffixResults = backtrack(s.substr(i + 1));
                
                for (const string& suffix : suffixResults) {
                    if (suffix.empty()) {
                        results.push_back(currentWord);
                    } else {
                        results.push_back(currentWord + " " + suffix);
                    }
                }
            }
        }

        memo[s] = results; 
        return results;
    }
};
