// thesid01

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
const vector<int> dx = {-1, 0, 1, 0};
const vector<int> dy = {0, -1, 0, 1};

struct TrieNode {
    TrieNode* childs[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            childs[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

void insertInTrie(string &str, TrieNode* root) {
    TrieNode* node = root;
    for(auto &ch: str) {
        if(node->childs[ch - 'a'] == nullptr) {
            node->childs[ch - 'a'] = new TrieNode();
        } 
        node = node->childs[ch - 'a'];
    }
    node->isEndOfWord = true;
}

int countWays(int start, string& word, TrieNode* root, vector<int> &dp) {

    int ways = 0;
    TrieNode* node = root;

    for (size_t i = start; i < word.size(); i++) {

        if (node->childs[word[i] - 'a'] == nullptr)
            return ways;

        node = node->childs[word[i] - 'a'];
        if (node->isEndOfWord) 
            ways = (ways + dp[i + 1]) % MOD; 
    }
    return ways;
}

int main() {
    string word;
    cin>>word;

    int n;
    cin>>n;

    TrieNode* trie = new TrieNode();
    
    for(int i=0; i<n; i++) {
        string s;
        cin>>s;

        insertInTrie(s, trie);
    }

    vector<int> dp(word.size() + 1, 0);
    
    // base case
    dp[word.size()] = 1;

    for(int i=word.size() - 1; i>=0; i--) {
        dp[i] = countWays(i, word, trie, dp);
    }

    cout<<dp[0]<<endl;

    return 0;
}
