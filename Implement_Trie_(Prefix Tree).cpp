#include <iostream>
#include <string>
using namespace std;

class Trie {
private:
    typedef struct TrieNode{
        int count;
        TrieNode *child[26];
        TrieNode(int cnt):count(cnt){
            for(int i=0 ; i<26 ; ++i)
                child[i] = nullptr;
        }
    }TrieNode;
    TrieNode *head;
public:
    /** Initialize your data structure here. */
    Trie() {
        head = new TrieNode(0);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* iter = head;
        for(int i=0 ; i<word.size() ; ++i){
            if(iter->child[word[i]-'a'] == nullptr)
                iter->child[word[i]-'a'] = new TrieNode(0);
            iter = iter->child[word[i]-'a'];
        }
        ++iter->count;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* iter = head;
        for(int i=0 ; i<word.size() ; ++i){
            if(!iter->child[word[i]-'a'])
                return false;
            iter = iter->child[word[i]-'a'];
        }
        return iter->count > 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* iter = head;
        for(int i=0 ; i<prefix.size() ; ++i){
            if(!iter->child[prefix[i]-'a'])
                return false;
            iter = iter->child[prefix[i]-'a'];
        }
        return true;
    }
};

int main(){
    Trie* obj = new Trie();
    string word("apple");
    obj->insert(word);
    bool param_2 = obj->search("app");
    bool param_3 = obj->startsWith("app");
    cout << boolalpha << param_2 << '\n';
    cout << boolalpha << param_3 << '\n';
}